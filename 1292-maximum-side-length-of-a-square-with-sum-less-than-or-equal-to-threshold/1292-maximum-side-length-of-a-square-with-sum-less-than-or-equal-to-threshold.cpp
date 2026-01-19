// class Solution {
// public:
// // DO NOT SUBMIT — Brute Force
// int maxSideLength(vector<vector<int>>& mat, int threshold) {
//     int m = mat.size();
//     int n = mat[0].size();
//     int ans = 0;

//     // Loop over all possible top-left corners
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {

//             // Try all possible square sizes
//             for (int k = 1; i + k <= m && j + k <= n; k++) {
//                 int sum = 0;

//                 // Compute sum of k x k square
//                 for (int r = i; r < i + k; r++) {
//                     for (int c = j; c < j + k; c++) {
//                         sum += mat[r][c];
//                     }
//                 }

//                 if (sum <= threshold) {
//                     ans = max(ans, k);
//                 }
//             }
//         }
//     }
//     return ans;
// }
// };

// Optimized approach
// Approach:
// 1. Build 2D prefix sum to compute any submatrix sum in O(1)
// 2. Binary search on possible side lengths
// 3. Check feasibility of a given side length

// Time Complexity: O(m * n * log(min(m, n)))
// Space Complexity: O(m * n)

// Memorize This !!
// Prefix indices are exclusive boundaries.
// Matrix indices are inclusive.
// Never mix them.

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum matrix with extra row and column for boundary handling
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        // Build prefix sum matrix
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Current cell value
                int current = mat[i - 1][j - 1];

                // Inclusion-exclusion principle
                prefix[i][j] = current + prefix[i - 1][j] + prefix[i][j - 1] -
                               prefix[i - 1][j - 1];
            }
        }

        // Binary search bounds
        int left = 0;
        int right = min(m, n);

        // Final answer
        int ans = 0;

        // Binary search on side length
        while (left <= right) {

            // Mid side length
            int mid = left + (right - left) / 2;

            // Flag to check if mid is feasible
            bool found = false;

            // Try all possible top-left corners
            for (int i = 0; i + mid <= m && !found; i++) {
                for (int j = 0; j + mid <= n; j++) {

                    // Compute sum of mid x mid square
                    int sum = prefix[i + mid][j + mid] // big rectangle
                                - prefix[i][j + mid] // remove top
                                - prefix[i + mid][j] // remove left
                                + prefix[i][j]; // add overlap back as top-left overlap area was subtracted twice.

                    // Check against threshold
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
            }

            // If square exists, try larger
            if (found) {
                ans = mid;
                left = mid + 1;
            }
            // Else try smaller
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
