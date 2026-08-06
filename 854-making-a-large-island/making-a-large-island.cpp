class DisjointSet {
    vector<int> rank, size, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find the ultimate parent (with path compression)
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    // Return the size of the component whose parent is "node"
    int getSize(int node) {
        return size[node];
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // ---------------------------------------------------------
        // Step 1 : Connect all adjacent 1's into one component
        // ---------------------------------------------------------
        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int newRow = row + dr[k];
                    int newCol = col + dc[k];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1) {

                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int ans = 0;

        // ---------------------------------------------------------
        // Step 2 : Try converting every 0 into 1
        // ---------------------------------------------------------
        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                set<int> components;

                // Store all unique neighbouring components
                for (int k = 0; k < 4; k++) {

                    int newRow = row + dr[k];
                    int newCol = col + dc[k];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1) {

                        int parent =
                            ds.findUPar(newRow * n + newCol);

                        components.insert(parent);
                    }
                }

                int totalSize = 1; // Current flipped cell

                // Add sizes of all unique neighbouring islands
                for (auto parent : components) {
                    totalSize += ds.getSize(parent);
                }

                ans = max(ans, totalSize);
            }
        }

        // ---------------------------------------------------------
        // Step 3 : Handle case when grid contains all 1's
        // ---------------------------------------------------------
        for (int cell = 0; cell < n * n; cell++) {

            if (ds.findUPar(cell) == cell) {
                ans = max(ans, ds.getSize(cell));
            }
        }

        return ans;
    }
};