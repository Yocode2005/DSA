class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the ultimate parent (with path compression)
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    // Union by size
    void unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        // Total number of nodes
        DisjointSet ds(n * n);

        /*
            pos[value] = {row,col}

            Since every value appears exactly once,
            we can directly know which cell becomes
            active at every time.
        */
        vector<pair<int,int>> pos(n * n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // Keeps track of cells that are underwater no more.
        vector<vector<bool>> active(n, vector<bool>(n, false));

        // Directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Increase water level gradually
        for(int time = 0; time < n * n; time++) {

            // Cell whose elevation equals current water level
            auto [row, col] = pos[time];

            // This cell is now accessible
            active[row][col] = true;

            int node = row * n + col;

            // Check all four neighbours
            for(int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                // Skip outside grid
                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                // Union only with already active neighbours
                if(active[nr][nc]) {

                    int adjNode = nr * n + nc;

                    ds.unionBySize(node, adjNode);
                }
            }

            // If start and end belong to same component,
            // answer is current time.
            if(ds.findUPar(0) == ds.findUPar(n * n - 1))
                return time;
        }

        return -1;
    }
};