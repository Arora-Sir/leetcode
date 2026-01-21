class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            int current = -1;
            for (int bit = 30; bit >= 0; bit--) {
                if ((num & (1 << bit)) == 0) continue;
                int x = num ^ (1 << bit);
                if ((x | (x + 1)) == num) {
                    current = x;
                    break;
                }
            }
            ans.push_back(current);
        }
        return ans;
    }
};