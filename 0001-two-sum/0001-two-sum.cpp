class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0;i<nums.size()-1;i++){
            int k = target - nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(k-nums[j] == 0) return {i, j};
            }
        }
        return {};
    }
};