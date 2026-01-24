/*
Approach:
Sort the array. Pair smallest with largest using two pointers.
Track the maximum sum among all pairs.

Core Insight:
Pairing extremes prevents large numbers from stacking together.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) extra (ignoring sort space)
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort array to access smallest and largest elements easily
        sort(nums.begin(), nums.end());
    
        int left = 0;
        int right = nums.size() - 1;
        int maxPairSum = 0; 

        // Continue until all elements are paired
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            maxPairSum = max(maxPairSum, currentSum);
            left++;
            right--;
        }

        return maxPairSum;
    }
};
