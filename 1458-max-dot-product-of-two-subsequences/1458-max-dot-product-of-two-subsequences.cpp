class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // dp[i][j] = max dot product for nums1[0..i-1], nums2[0..j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MIN));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]); // skip nums1[i-1]
                dp[i][j] = max(dp[i][j], dp[i][j-1]); // skip nums2[j-1]

                int prod = nums1[i-1] * nums2[j-1];  // take both i-1 and j-1 indices
                dp[i][j] = max(dp[i][j], max(0, dp[i-1][j-1]) + prod);  // add prod to previous best (or start fresh if negative)
            }
        }
        return dp[m][n];
    }
};