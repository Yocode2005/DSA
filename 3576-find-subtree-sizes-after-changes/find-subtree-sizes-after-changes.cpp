class Solution {
public:

    void dfs(int u,
             vector<vector<int>>& adj,
             string& s,
             vector<int>& parent,
             vector<int>& newParent,
             vector<int>& last) {

        int c = s[u] - 'a';

        // Save the previous ancestor having the same character
        int previous = last[c];

        // If there is an ancestor with the same character,
        // make that ancestor the new parent.
        if (last[c] != -1) {
            newParent[u] = last[c];
        } else {
            newParent[u] = parent[u];
        }

        // Current node becomes the closest ancestor
        // having character s[u].
        last[c] = u;

        // Traverse children in the original tree
        for (int v : adj[u]) {
            dfs(v, adj, s, parent, newParent, last);
        }

        // Restore the previous ancestor
        // because u is no longer on the current DFS path.
        last[c] = previous;
    }

    int calculateSize(int u,
                      vector<vector<int>>& newTree,
                      vector<int>& ans) {

        int size = 1;

        for (int v : newTree[u]) {
            size += calculateSize(v, newTree, ans);
        }

        ans[u] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        // Original tree
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // New parent after applying the rule
        vector<int> newParent = parent;

        // last[c] = closest ancestor with character c
        vector<int> last(26, -1);

        // Root has no parent
        newParent[0] = -1;

        // Find the new parent of every node
        dfs(0, adj, s, parent, newParent, last);

        // Build the final tree
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n);

        calculateSize(0, newTree, ans);

        return ans;
    }
};