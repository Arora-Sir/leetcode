// class Solution {
// public:
//     // Check if k x k square starting at (r, c) is magic (brute force)
//     bool isMagicBrute(vector<vector<int>>& grid, int r, int c, int k) {

//         // Calculate sum of the first row to use as target
//         int target = 0;
//         for (int j = 0; j < k; j++)
//             target += grid[r][c + j];

//         // Check all rows
//         for (int i = 0; i < k; i++) {
//             int sum = 0;
//             for (int j = 0; j < k; j++)
//                 sum += grid[r + i][c + j];
//             if (sum != target)
//                 return false;
//         }

//         // Check all columns
//         for (int j = 0; j < k; j++) {
//             int sum = 0;
//             for (int i = 0; i < k; i++)
//                 sum += grid[r + i][c + j];
//             if (sum != target)
//                 return false;
//         }

//         // Check both diagonals
//         int d1 = 0, d2 = 0;
//         for (int i = 0; i < k; i++) {
//             d1 += grid[r + i][c + i];         // main diagonal
//             d2 += grid[r + i][c + k - 1 - i]; // anti diagonal
//         }

//         return d1 == target && d2 == target;
//     }

//     int largestMagicSquare(vector<vector<int>>& grid) {
//         int m = grid.size();    // number of rows
//         int n = grid[0].size(); // number of columns

//         int ans = 1; // 1x1 is always magic

//         // Try all square sizes
//         for (int k = 2; k <= min(m, n); k++) {
//             for (int i = 0; i + k <= m; i++) {
//                 for (int j = 0; j + k <= n; j++) {
//                     if (isMagicBrute(grid, i, j, k))
//                         ans = k;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int m = grid.size();    // total rows
        int n = grid[0].size(); // total columns

        // Prefix sums for rows
        vector<vector<int>> row(m, vector<int>(n + 1, 0));

        // Prefix sums for columns
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Build prefix sum arrays
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Sum of row i from column 0 to j
                row[i][j + 1] = row[i][j] + grid[i][j];

                // Sum of column j from row 0 to i
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        // Try largest squares first
        for (int k = min(m, n); k >= 2; k--) {

            // Top-left row of square
            for (int i = 0; i + k <= m; i++) {

                // Top-left column of square
                for (int j = 0; j + k <= n; j++) {

                    // Target sum: first row of square
                    int target = row[i][j + k] - row[i][j];

                    bool ok = true;

                    // Check all rows
                    for (int r = i; r < i + k && ok; r++) {
                        if (row[r][j + k] - row[r][j] != target)
                            ok = false;
                    }

                    // Check all columns
                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != target)
                            ok = false;
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    // If everything matches, this is the largest possible
                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }

        // If no square >1 found
        return 1;
    }
};
