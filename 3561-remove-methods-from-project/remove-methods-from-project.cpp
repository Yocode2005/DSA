class Solution {
public:
    // DFS to mark all suspicious methods
    void dfs(int node, vector<vector<int>> &adj, vector<int> &suspicious) {
        suspicious[node] = 1;

        for (int next : adj[node]) {
            if (!suspicious[next]) {
                dfs(next, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Create adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // suspicious[i] = 1 means method i is suspicious
        vector<int> suspicious(n, 0);

        // Mark every method reachable from k
        dfs(k, adj, suspicious);

        // Check whether any non-suspicious method
        // invokes a suspicious method.
        // If yes, removal is impossible.
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;

                // Return all methods
                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // Otherwise, keep only non-suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};