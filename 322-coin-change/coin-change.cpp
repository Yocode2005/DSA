class Solution {
public:
    int solve(int idx,vector<int>& coins, int targetAmount,vector<vector<int>>&dp){
        if(idx == 0){
            if(targetAmount%coins[idx] == 0) return targetAmount/coins[idx];
            return 1e9;
        }
        if(dp[idx][targetAmount] != -1) return dp[idx][targetAmount];
        int notTake = 0 + solve(idx-1,coins,targetAmount,dp);
        int take = INT_MAX;
        if(coins[idx]<=targetAmount){
            take = 1+solve(idx,coins,targetAmount-coins[idx],dp);
        }
        return dp[idx][targetAmount] =  min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            int ans =  solve(n-1,coins,amount,dp);
            return (ans >= 1e9) ? -1 : ans;
    }
};