class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        long long mn = LLONG_MAX;
        int negative = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                sum += abs(matrix[i][j]);

                if (matrix[i][j] < 0) {
                    negative++;
                }

                mn = min(mn, (long long)abs(matrix[i][j]));
            }
        }

        if (negative % 2 == 0) {
            return sum;
        }

        return sum - 2LL * mn;
    }
};