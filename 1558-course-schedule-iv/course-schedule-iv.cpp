class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<bool>> pre(n, vector<bool>(n, false));

        // Direct prerequisites
        for (auto &it : prerequisites) {
            pre[it[0]][it[1]] = true;
        }

        // Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    pre[i][j] = pre[i][j] || (pre[i][via] && pre[via][j]);
                }
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(pre[q[0]][q[1]]);
        }

        return ans;
    }
};