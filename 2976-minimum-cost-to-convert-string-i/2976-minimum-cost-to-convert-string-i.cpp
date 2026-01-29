//// Floyd–Warshall to compute all-pairs shortest paths

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
                            
        // Use long long because total cost can exceed int range
        const long long INF = 1e18;

        // Distance matrix for 26 lowercase letters
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // Cost to convert a character to itself is zero
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Fill direct transformation costs
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a'; // Convert char to index
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall to compute all-pairs shortest paths
        for (int k = 0; k < 26; k++) {         // Intermediate node
            for (int i = 0; i < 26; i++) {     // Source node
                for (int j = 0; j < 26; j++) { // Destination node
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Compute total cost for transforming source → target
        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            // If conversion is impossible
            if (dist[u][v] == INF) {
                return -1;
            }

            ans += dist[u][v];
        }

        return ans;
    }
};