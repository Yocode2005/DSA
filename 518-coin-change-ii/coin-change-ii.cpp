class Solution {
public:
    int solve(int idx, int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(idx == 0){
            if(amount%coins[0] == 0) return 1;
            return 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = solve(idx-1,amount,coins,dp);
        int take = 0;
        if(coins[idx]<= amount){
            take = solve(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount] =  notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};