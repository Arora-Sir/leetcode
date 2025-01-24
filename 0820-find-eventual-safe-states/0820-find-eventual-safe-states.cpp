#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), check(n, -1);
        vector<int> safeNodes;

        for (int i = 0; i < n; i++) {
            if (dfsCheck(i, graph, vis, pathVis, check) == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
    
    int dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        // If already checked, return the result
        if (check[node] != -1) {
            return check[node];
        }
        
        // Mark the current node as visited and in the current path
        vis[node] = 1;
        pathVis[node] = 1;

        // Traverse the adjacent nodes
        for (int it : graph[node]) {
            // If the adjacent node is not visited yet
            if (vis[it] == 0) {
                if (dfsCheck(it, graph, vis, pathVis, check) == 0) {
                    return check[node] = 0; // Cycle detected
                }
            } else if (pathVis[it] == 1) { //Checking the cycle for the current node if we visit pathVisited again
                return check[node] = 0; // Cycle detected, unsafe
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return check[node];
    }
};