class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[],
             vector<int>& visited, int tin[], int low[],
             vector<vector<int>>& bridges) {

        visited[node] = 1;

        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]) {

            // Ignore the edge from node to its parent
            if (it == parent)
                continue;

            // If node is not visited
            if (visited[it] == 0) {

                dfs(it, node, adj, visited, tin, low, bridges);

                // Update low value of current node
                low[node] = min(low[node], low[it]);

                // Check whether edge node -> it is a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }

            // Back edge
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<int> adj[n];

        // Build adjacency list
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        int tin[n];
        int low[n];

        vector<vector<int>> bridges;

        dfs(0, -1, adj, visited, tin, low, bridges);

        return bridges;
    }
};