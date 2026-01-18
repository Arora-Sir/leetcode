class Solution {
public:
    bool isMagicBrute(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;
        for (int j = 0; j < k; j++)
            target += grid[r][c + j];

        // rows
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++)
                sum += grid[r + i][c + j];
            if (sum != target)
                return false;
        }

        // columns
        for (int j = 0; j < k; j++) {
            int sum = 0;
            for (int i = 0; i < k; i++)
                sum += grid[r + i][c + j];
            if (sum != target)
                return false;
        }

        // diagonals
        int d1 = 0, d2 = 0;
        for (int i = 0; i < k; i++) {
            d1 += grid[r + i][c + i];
            d2 += grid[r + i][c + k - 1 - i];
        }

        return d1 == target && d2 == target;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagicBrute(grid, i, j, k))
                        ans = k;
                }
            }
        }
        return ans;
    }
};
