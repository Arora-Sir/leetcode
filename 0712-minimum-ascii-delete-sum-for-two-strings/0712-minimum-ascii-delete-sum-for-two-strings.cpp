/*
    Problem: Minimum ASCII Delete Sum for Two Strings (LeetCode 712)

        Brute Force Idea (NOT IMPLEMENTED):
        ----------------------------------
        - Generate all subsequences of s1
        - Generate all subsequences of s2
        - For every common subsequence:
            delete everything else
            calculate total ASCII delete cost
        - Return minimum cost

        Why brute force fails:
        - Each string has 2^n subsequences
        - Comparing all pairs is exponential
        - Impossible for n up to 1000
        
        Optimized Approach Used Here:
        -----------------------------
        - This is a variation of LCS (Longest Common Subsequence)
        - Instead of maximizing length, we maximize ASCII sum
        - We keep the most "valuable" common subsequence
        - Then delete everything else

        Key Formula:
        -----------
        minimum delete cost = (ASCII sum of s1 + ASCII sum of s2) - 2 * (maximum ASCII sum of common subsequence)
        */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        // Lengths of both strings
        int m = s1.size(), n = s2.size();

        /*
            dp[i][j] = maximum ASCII sum of a common subsequence between s1[0..i-1] and s2[0..j-1]
            This is similar to LCS DP, but instead of counting length, we accumulate ASCII values.
        */

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build the DP table row by row
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If characters match, we KEEP them
                // Add ASCII value to the previous best
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                }
                // If characters don't match,
                // we skip one character (like LCS)
                else {
                    dp[i][j] = max(dp[i - 1][j], // skip character from s1
                                   dp[i][j - 1]  // skip character from s2
                    );
                }
            }
        }

        // Calculate total ASCII sum of s1
        int sum1 = 0;
        for (char c : s1)
            sum1 += c;

        // Calculate total ASCII sum of s2
        int sum2 = 0;
        for (char c : s2)
            sum2 += c;

        /*
            Final Answer:
            - dp[m][n] is the maximum ASCII sum we can KEEP
            - We subtract it twice because:
                once from s1
                once from s2
        */
        
        return sum1 + sum2 - 2 * dp[m][n];
    }
};
