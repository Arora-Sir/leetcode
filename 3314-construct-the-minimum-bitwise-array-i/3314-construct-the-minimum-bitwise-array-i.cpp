class Solution {
public:
    // vector<int> minBitwiseArray(vector<int>& nums) {
    //     vector<int> ans;
    //     int current = -1;
    //     for(auto& num : nums){
    //         current = -1;
    //         for(int i=0;i<=num;i++){
    //             if(((i) | (i+1)) == num){
    //                 current = i;
    //                 break;
    //             }
    //         }
    //         ans.push_back(current);
    //     }
    //     return ans;
    // }

    //     Key insights from this problem:
    //         OR never removes 1s
    //         x + 1 can only add one new 1
    //     So num must be formed by :
    //         taking x, and 
    //         turning one bit ON
    //     Therefore, reversing it means :
    //         Take num and turn OFF exactly one 1 bit that gives a candidate x

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {

            int best = -1;

            // Try turning off each set bit
            for (int bit = 0; bit < 31; bit++) {

                // Check if this bit is set in num
                // Only consider bits that are actually 1 in num.
                if ((num & (1 << bit)) == 0)
                    continue;

                // Turn off this bit
                int x = num ^ (1 << bit);

                // x must be non-negative
                if (x < 0)
                    continue;

                // Check if it satisfies the condition
                if ((x | (x + 1)) == num) {
                    if (best == -1 || x < best) {
                        best = x;
                    }
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};