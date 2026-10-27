class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initially, fill the entire grid with obstacles
        vector<string> grid(m, string(n, '#'));

        // Make every cell in the first row free
        grid[0] = string(n, '.');

        // Make every cell in the last column free
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};