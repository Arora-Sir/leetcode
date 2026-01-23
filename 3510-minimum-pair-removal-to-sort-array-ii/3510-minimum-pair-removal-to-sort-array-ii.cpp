class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        // If the array has 0 or 1 elements, it is already non-decreasing
        // So no operations are required
        if (n <= 1)
            return 0;

        // We use a map to simulate the array dynamically
        // key   -> original index (to preserve left-right ordering)
        // value -> current value at that position
        //
        // Why map?
        // - Maintains sorted order of indices automatically
        // - Allows easy access to previous and next neighbors
        // - Supports deletion in O(log n)
        map<int, long long> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = nums[i];
        }

        // This set stores all adjacent pair sums
        // Each element is (sum_of_pair, left_index_of_pair)
        //
        // Why left index?
        // - If multiple pairs have the same minimum sum,
        //   the problem requires choosing the LEFTMOST one
        //
        // Why set?
        // - Always gives us the minimum sum pair in O(log n)
        set<pair<long long, int>> st;

        // Insert all initial adjacent pair sums
        for (int i = 0; i < n - 1; i++) {
            st.insert({nums[i] + nums[i + 1], i});
        }

        // badPairs counts how many adjacent inversions exist
        // An inversion means nums[i] > nums[i+1]
        //
        // The array is non-decreasing if and only if badPairs == 0
        //
        // This variable is critical to avoid TLE:
        // Instead of checking the whole array every time,
        // we update this count incrementally
        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                badPairs++;
            }
        }

        // If there are no inversions initially,
        // the array is already non-decreasing
        // This handles cases like [1,1,1,1,1,...]
        if (badPairs == 0)
            return 0;

        // This will store the number of merge operations performed
        int operations = 0;

        // We must keep merging until there are no inversions left
        // We are NOT allowed to stop earlier
        while (badPairs > 0) {

            // Always select the globally minimum sum adjacent pair
            // This is a strict rule from the problem statement
            auto [sum, idx] = *st.begin();
            st.erase(st.begin());

            // The left index might already have been removed
            // due to a previous merge, so we skip if it no longer exists
            if (!mp.count(idx))
                continue;

            // it1 points to the left element of the chosen pair
            auto it1 = mp.find(idx);

            // it2 points to the right element of the chosen pair
            auto it2 = std::next(it1);

            // If there is no right neighbor, this pair is invalid
            if (it2 == mp.end())
                continue;

            // -------- BEFORE MERGE --------
            // We are about to destroy some adjacency relationships
            // So we must:
            // 1) Remove their sums from the set
            // 2) Decrease badPairs where inversions disappear

            // Case 1: (leftNeighbor, it1)
            if (it1 != mp.begin()) {
                auto left = std::prev(it1);

                // If this pair was an inversion, it will disappear after merge
                if (left->second > it1->second) {
                    badPairs--;
                }

                // Remove the old adjacent sum from the set
                st.erase({left->second + it1->second, left->first});
            }

            // Case 2: (it1, it2)
            // This adjacency will be destroyed by the merge
            if (it1->second > it2->second) {
                badPairs--;
            }

            // Case 3: (it2, rightNeighbor)
            auto right = std::next(it2);
            if (right != mp.end()) {

                // If this was an inversion, it will disappear
                if (it2->second > right->second) {
                    badPairs--;
                }

                // Remove the old adjacent sum from the set
                st.erase({it2->second + right->second, it2->first});
            }

            // -------- MERGE OPERATION --------
            // Replace the pair (it1, it2) with their sum at it1
            // it2 is removed from the array
            it1->second += it2->second;
            mp.erase(it2);

            // -------- AFTER MERGE --------
            // New adjacency relationships are formed
            // We must:
            // 1) Add their sums to the set
            // 2) Increase badPairs if new inversions appear

            // Case 4: (leftNeighbor, mergedNode)
            if (it1 != mp.begin()) {
                auto left = std::prev(it1);

                // Check if a new inversion is created
                if (left->second > it1->second) {
                    badPairs++;
                }

                // Insert the new adjacent sum
                st.insert({left->second + it1->second, left->first});
            }

            // Case 5: (mergedNode, rightNeighbor)
            right = std::next(it1);
            if (right != mp.end()) {

                // Check if a new inversion is created
                if (it1->second > right->second) {
                    badPairs++;
                }

                // Insert the new adjacent sum
                st.insert({it1->second + right->second, it1->first});
            }

            // One merge operation has been completed
            operations++;
        }

        // When badPairs becomes zero,
        // the array is guaranteed to be non-decreasing
        return operations;
    }
};