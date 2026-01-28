// Modified Dijkastra's Algorithm (instead of using DP):

class Solution {
public:
    int n, m;

    // Check grid bounds (only right and down allowed)
    bool valid(int i, int j) { return i < n && j < m; }

    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        // STEP 1: Flatten the grid into (value, row, col)
        vector<tuple<int, int, int>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        // Sort cells by value (ascending)
        sort(cells.begin(), cells.end());

        // STEP 2: Distance array
        // dist[i][j][t] = minimum cost to reach (i,j) using t teleports
        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));

        // STEP 3: For each teleport count t, how many cells (from sorted list) have already been processed
        vector<int> teleportPtr(k + 1, 0);

        // STEP 4: Dijkstra priority queue
        // (cost, teleportsUsed, row, col)
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>, 
                       greater<>> pq;

        // Start at (0,0) with 0 cost and 0 teleports
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        // STEP 5: Dijkstra loop
        while (!pq.empty()) {

            auto [cost, used, i, j] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (cost != dist[i][j][used])
                continue;

            // Destination reached with minimum cost
            if (i == n - 1 && j == m - 1) {
                return cost;
            }

            // Normal move: DOWN
            if (valid(i + 1, j)) {
                int newCost = cost + grid[i + 1][j];
                if (newCost < dist[i + 1][j][used]) {
                    dist[i + 1][j][used] = newCost;
                    pq.push({newCost, used, i + 1, j});
                }
            }

            // Normal move: RIGHT
            if (valid(i, j + 1)) {
                int newCost = cost + grid[i][j + 1];
                if (newCost < dist[i][j + 1][used]) {
                    dist[i][j + 1][used] = newCost;
                    pq.push({newCost, used, i, j + 1});
                }
            }

            // Teleport move
            if (used < k) {

                // Pointer for this teleport count
                int& ptr = teleportPtr[used];

                // Process all cells with value <= current cell value
                while (ptr < (int)cells.size()) {

                    auto [val, ni, nj] = cells[ptr];

                    // Stop when teleport condition breaks
                    if (val > grid[i][j])
                        break;

                    // Relax teleport edge (cost = 0)
                    if (cost < dist[ni][nj][used + 1]) {
                        dist[ni][nj][used + 1] = cost;
                        pq.push({cost, used + 1, ni, nj});
                    }

                    // Move pointer forward
                    ptr++;
                }
            }
        }

        // If unreachable (should not happen per problem)
        return -1;
    }
};