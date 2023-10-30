class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int countZeros=0;
        int j=0;
        vector<int> output(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            // if(nums[i]==0) countZeros++;
            if(nums[i]!=0){
                output[j++] = nums[i];
            }
        }
        nums = output;
    }
};