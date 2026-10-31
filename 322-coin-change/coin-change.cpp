// class Solution {
// public:
//     int solve(int idx,vector<int>& coins, int targetAmount,vector<vector<int>>&dp){
//         if(idx == 0){
//             if(targetAmount%coins[idx] == 0) return targetAmount/coins[idx];
//             return 1e9;
//         }
//         if(dp[idx][targetAmount] != -1) return dp[idx][targetAmount];
//         int notTake = 0 + solve(idx-1,coins,targetAmount,dp);
//         int take = INT_MAX;
//         if(coins[idx]<=targetAmount){
//             take = 1+solve(idx,coins,targetAmount-coins[idx],dp);
//         }
//         return dp[idx][targetAmount] =  min(notTake,take);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//             int ans =  solve(n-1,coins,amount,dp);
//             return (ans >= 1e9) ? -1 : ans;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int targetAmount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(targetAmount+1,0));
        for(int target = 0;target<=targetAmount;target++){
            if(target%coins[0] == 0){
                 dp[0][target] = target/coins[0];
            }
            else{
                dp[0][target] = 1e9;
            }
        }
        for(int idx = 1;idx<n;idx++){
            for(int target = 0;target<=targetAmount;target++){
                 int notTake = 0 + dp[idx-1][target];
                    int take = 1e9;
                    if(coins[idx]<=target){
                    take = 1+dp[idx][target-coins[idx]];
        }
                dp[idx][target] =  min(notTake,take);
            }
        }
        int ans = dp[n-1][targetAmount];
        return (ans >= 1e9) ? -1 : ans;
    }
};