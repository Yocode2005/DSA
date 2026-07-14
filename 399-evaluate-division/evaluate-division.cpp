class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, int> mp;
        int idx = 0;

        // Assign an index to every unique variable
        for (auto &eq : equations) {
            if (!mp.count(eq[0]))
                mp[eq[0]] = idx++;
            if (!mp.count(eq[1]))
                mp[eq[1]] = idx++;
        }

        int n = idx;

        // dist[i][j] = value of (variable_i / variable_j)
        vector<vector<double>> dist(n, vector<double>(n, -1.0));

        // Every variable divided by itself is 1
        for (int i = 0; i < n; i++)
            dist[i][i] = 1.0;

        // Store the given equations
        for (int i = 0; i < equations.size(); i++) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];

            dist[u][v] = values[i];
            dist[v][u] = 1.0 / values[i];
        }

        // Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][via] == -1.0)
                    continue;

                for (int j = 0; j < n; j++) {
                    if (dist[via][j] == -1.0)
                        continue;

                    if (dist[i][j] == -1.0)
                        dist[i][j] = dist[i][via] * dist[via][j];
                }
            }
        }

        // Answer queries
        vector<double> ans;

        for (auto &q : queries) {
            if (!mp.count(q[0]) || !mp.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }

            ans.push_back(dist[mp[q[0]]][mp[q[1]]]);
        }

        return ans;
    }
};