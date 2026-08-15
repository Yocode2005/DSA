class Solution {
public:

    // ----------------------------------------------------
    // STEP 1:
    // DFS and store nodes according to finishing time
    // ----------------------------------------------------
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& topo) {

        vis[node] = 1;

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis, topo);
            }
        }

        // Node is pushed AFTER visiting all neighbours
        // This gives finishing order
        topo.push_back(node);
    }


    // ----------------------------------------------------
    // STEP 4:
    // DFS on transpose graph to find SCC
    // ----------------------------------------------------
    void dfsTranspose(int node,
                      vector<vector<int>>& transpose,
                      vector<int>& vis,
                      vector<int>& component,
                      int id) {

        vis[node] = 1;

        component[node] = id;

        for (int next : transpose[node]) {

            if (!vis[next]) {
                dfsTranspose(
                    next,
                    transpose,
                    vis,
                    component,
                    id
                );
            }
        }
    }


    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // ----------------------------------------------------
        // Find first and last occurrence of every character
        // ----------------------------------------------------

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }


        // ----------------------------------------------------
        // STEP 1:
        // Build dependency graph
        //
        // c -> x
        //
        // means x lies inside the range of c
        // ----------------------------------------------------

        vector<vector<int>> adj(26);

        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            for (int i = first[c]; i <= last[c]; i++) {

                int x = s[i] - 'a';

                adj[c].push_back(x);
            }
        }


        // ----------------------------------------------------
        // STEP 2:
        // DFS -> finishing order
        // ----------------------------------------------------

        vector<int> vis(26, 0);
        vector<int> topo;

        for (int i = 0; i < 26; i++) {

            if (last[i] != -1 && !vis[i]) {

                dfs(i, adj, vis, topo);
            }
        }


        // ----------------------------------------------------
        // STEP 3:
        // Create TRANSPOSE graph
        //
        // If:
        //     u -> v
        //
        // then:
        //     v -> u
        // ----------------------------------------------------

        vector<vector<int>> transpose(26);

        for (int u = 0; u < 26; u++) {

            for (int v : adj[u]) {

                transpose[v].push_back(u);
            }
        }


        // ----------------------------------------------------
        // STEP 4:
        // DFS on transpose graph
        //
        // Process vertices in REVERSE finishing order
        // ----------------------------------------------------

        fill(vis.begin(), vis.end(), 0);

        vector<int> component(26, -1);

        int id = 0;

        for (int i = topo.size() - 1; i >= 0; i--) {

            int node = topo[i];

            if (!vis[node]) {

                dfsTranspose(
                    node,
                    transpose,
                    vis,
                    component,
                    id
                );

                id++;
            }
        }


        // ----------------------------------------------------
        // STEP 5:
        // Find SCCs which have NO outgoing edge
        // to another SCC.
        // ----------------------------------------------------

        vector<bool> outgoing(id, false);

        for (int u = 0; u < 26; u++) {

            if (last[u] == -1)
                continue;

            for (int v : adj[u]) {

                // Edge between two different SCCs
                if (component[u] != component[v]) {

                    outgoing[component[u]] = true;
                }
            }
        }


        // ----------------------------------------------------
        // STEP 6:
        // Every sink SCC represents a valid substring
        // ----------------------------------------------------

        vector<pair<int, int>> intervals;

        for (int comp = 0; comp < id; comp++) {

            // If this SCC has an outgoing edge,
            // it cannot be an independent substring.
            if (outgoing[comp])
                continue;

            int L = n;
            int R = -1;

            // Get complete range of this SCC
            for (int c = 0; c < 26; c++) {

                if (component[c] == comp) {

                    L = min(L, first[c]);
                    R = max(R, last[c]);
                }
            }

            if (R != -1) {

                intervals.push_back({L, R});
            }
        }


        // ----------------------------------------------------
        // STEP 7:
        // Sort substrings by starting index
        // ----------------------------------------------------

        sort(intervals.begin(), intervals.end());


        // ----------------------------------------------------
        // STEP 8:
        // Generate answer
        // ----------------------------------------------------

        vector<string> ans;

        for (auto [L, R] : intervals) {

            ans.push_back(
                s.substr(L, R - L + 1)
            );
        }

        return ans;
    }
};