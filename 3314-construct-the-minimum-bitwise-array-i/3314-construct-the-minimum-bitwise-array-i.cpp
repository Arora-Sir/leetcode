class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int current = -1;
        for(auto& num : nums){
            current = -1;
            for(int i=0;i<=num;i++){
                if(((i) | (i+1)) == num){
                    current = i;
                    break;
                }
            }
            ans.push_back(current);
        }
        return ans;
    }
};