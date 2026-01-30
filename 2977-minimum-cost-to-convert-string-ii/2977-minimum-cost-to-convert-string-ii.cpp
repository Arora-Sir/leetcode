class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = 1e18;
        int n = source.size();
        int m = original.size();

        // Group rules by length
        unordered_map<int, vector<int>> rulesByLen;
        for (int i = 0; i < m; i++) {
            rulesByLen[original[i].size()].push_back(i);
        }

        // Precompute min cost for each length using APSP
        unordered_map<int,
                      unordered_map<string, unordered_map<string, long long>>>
            minCost;

        for (auto& [len, idxs] : rulesByLen) {
            unordered_map<string, int> id;
            vector<string> nodes;

            for (int i : idxs) {
                if (!id.count(original[i])) {
                    id[original[i]] = nodes.size();
                    nodes.push_back(original[i]);
                }
                if (!id.count(changed[i])) {
                    id[changed[i]] = nodes.size();
                    nodes.push_back(changed[i]);
                }
            }

            int sz = nodes.size();
            vector<vector<long long>> dist(sz, vector<long long>(sz, INF));
            for (int i = 0; i < sz; i++)
                dist[i][i] = 0;

            for (int i : idxs) {
                int u = id[original[i]];
                int v = id[changed[i]];
                dist[u][v] = min(dist[u][v], (long long)cost[i]);
            }

            for (int k = 0; k < sz; k++)
                for (int i = 0; i < sz; i++)
                    for (int j = 0; j < sz; j++)
                        if (dist[i][k] + dist[k][j] < dist[i][j])
                            dist[i][j] = dist[i][k] + dist[k][j];

            for (int i = 0; i < sz; i++)
                for (int j = 0; j < sz; j++)
                    if (dist[i][j] < INF)
                        minCost[len][nodes[i]][nodes[j]] = dist[i][j];
        }

        // DP over indices
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF)
                continue;

            // SINGLE CHARACTER NO-OP
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Substring transitions
            for (auto& [len, mp] : minCost) {
                if (i + len > n)
                    continue;

                string A = source.substr(i, len);
                string B = target.substr(i, len);

                if (mp.count(A) && mp[A].count(B)) {
                    dp[i + len] = min(dp[i + len], dp[i] + mp[A][B]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};