class Solution {
public:
    int solve(int idx, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {

        // Base case: All travel days covered
        if(idx >= days.size()) {
            return 0;
        }

        // Already calculated
        if(dp[idx] != -1) {
            return dp[idx];
        }

        // Option 1: Buy 1-day pass
        int oneDay = costs[0] + solve(idx + 1, days, costs, dp);

        // Option 2: Buy 7-day pass
        int i = idx;

        while(i < days.size() && days[i] < days[idx] + 7) {
            i++;
        }

        int sevenDay = costs[1] + solve(i, days, costs, dp);

        // Option 3: Buy 30-day pass
        i = idx;

        while(i < days.size() && days[i] < days[idx] + 30) {
            i++;
        }

        int thirtyDay = costs[2] + solve(i, days, costs, dp);

        return dp[idx] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();

        vector<int> dp(n, -1);

        return solve(0, days, costs, dp);
    }
};