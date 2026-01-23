class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        // Map maintains current array with indices
        map<int, long long> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = nums[i];
        }

        // Set keeps (sum, leftIndex) for minimum adjacent pair
        set<pair<long long, int>> st;
        for (int i = 0; i < n - 1; i++) {
            st.insert({nums[i] + nums[i + 1], i});
        }

        // NEW ADDITION
        // Count how many adjacent pairs are violating non-decreasing order
        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                badPairs++;
        }

        // If already sorted, return immediately (handles all-equal case)
        if (badPairs == 0)
            return 0;

        int operations = 0;

        while (badPairs > 0) {

            // Always pick globally minimum sum pair
            auto [sum, idx] = *st.begin();
            st.erase(st.begin());

            // idx must still exist
            if (!mp.count(idx))
                continue;

            auto it1 = mp.find(idx);
            auto it2 = std::next(it1);
            if (it2 == mp.end())
                continue;

            // --- BEFORE MERGE: update badPairs (remove old relationships) ---

            // Left neighbor → it1
            if (it1 != mp.begin()) {
                auto left = std::prev(it1);
                if (left->second > it1->second)
                    badPairs--;
                st.erase({left->second + it1->second, left->first});
            }

            // it1 → it2
            if (it1->second > it2->second)
                badPairs--;

            // it2 → right neighbor
            auto right = std::next(it2);
            if (right != mp.end()) {
                if (it2->second > right->second)
                    badPairs--;
                st.erase({it2->second + right->second, it2->first});
            }

            // --- MERGE ---
            it1->second += it2->second;
            mp.erase(it2);

            // --- AFTER MERGE: add new relationships ---

            // Left neighbor → merged node
            if (it1 != mp.begin()) {
                auto left = std::prev(it1);
                if (left->second > it1->second)
                    badPairs++;
                st.insert({left->second + it1->second, left->first});
            }

            // Merged node → right neighbor
            right = std::next(it1);
            if (right != mp.end()) {
                if (it1->second > right->second)
                    badPairs++;
                st.insert({it1->second + right->second, it1->first});
            }

            operations++;
        }

        return operations;
    }
};