class Solution {
public:

    bool check(int k, vector<vector<int>>& mat,
               vector<vector<int>>& pref) {

        int m = mat.size();
        int n = mat[0].size();

        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i + k <= m; i++) {

            for (int j = 0; j + k <= n; j++) {

                // Sum of k x k square starting at (i, j)
                int sum = pref[i + k][j + k]
                        - pref[i][j + k]
                        - pref[i + k][j]
                        + pref[i][j];

                // Square is not completely filled with 1s
                if (sum != k * k)
                    continue;

                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }

        // No valid square
        if (maxRow == -1)
            return false;

        // Two squares can be separated vertically
        // OR horizontally.
        if (maxRow - minRow >= k ||
            maxCol - minCol >= k) {
            return true;
        }

        return false;
    }

    int maxArea(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum
        vector<vector<int>> pref(
            m + 1,
            vector<int>(n + 1, 0)
        );

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        int ans = 0;

        // Try every possible square size
        for (int k = 1; k <= min(m, n); k++) {

            if (check(k, mat, pref)) {
                ans = max(ans, k * k);
            }
        }

        return ans;
    }
};