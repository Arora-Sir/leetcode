class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Note: Don't look at example2-step2, as it seems misleading!
        int n = nums.size();

        // Step 1: Copy each number with its original index
        vector<pair<int, int>> copy;
        for (int i = 0; i < n; ++i) {
            copy.push_back({nums[i], i});
        }

        // Step 2: Sort the array based on values
        sort(copy.begin(), copy.end());

        // Step 3: Group and place ordered values
        int left = 0, right = 1; //Two-Pointer approach for tracking 1 group at a time
        while (right < n) {
            // Find the group and get their original indices
            vector<int> pos = {copy[left].second}; //Filling first element in position(indicies), as we need to compare from 2nd element
            while (right < n && abs(copy[right].first - copy[right - 1].first) <= limit) { //To see if its inside the group!
                pos.push_back(copy[right].second); //store all positions until first group ends
                right++;
            }

            // Order the indices of the perticular group
            sort(pos.begin(), pos.end());

            // Copy sorted values into sorted indices
            for (int i = 0; i < pos.size(); ++i) {
                nums[pos[i]] = copy[left + i].first;
            }

            // Move to the next group
            left = right;
            right++;
        }

        return nums;
    }
};
