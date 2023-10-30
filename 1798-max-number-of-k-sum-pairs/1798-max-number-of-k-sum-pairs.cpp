class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        // vector<int> TenNums;
        unordered_map<int, int> TenNums;
        for(int i=0;i<nums.size();i++){
            if(TenNums[k - nums[i]] > 0){
			   TenNums[k - nums[i]]--;
			    count++;
			}
			else{
                TenNums[nums[i]]++;
            }
        }
        return count;
    }
};