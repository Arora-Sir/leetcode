class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans =0;

        while(!isSorted(nums)){
            int minSum = INT_MAX;
            int idx = 0;
            for(int i=0;i<nums.size()-1;i++){
                if(minSum > (nums[i]+nums[i+1])){
                    idx = i;
                    minSum = nums[i]+nums[i+1];
                }
            }
            nums[idx] += nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }
        return ans;
    }
    bool isSorted(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
};