class Solution {
public:
    int solve(int row, int c1, int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(c1<0 || c1>= m || c2<0 || c2>=m){
            return -1e9;
        }
        if(row == n-1){
            if(c1 == c2) return grid[row][c1];
            else return grid[row][c1] + grid[row][c2];
        }
        if(dp[row][c1][c2] != -1){
            return dp[row][c1][c2];
        }
        int maxi = -1e9;
        for(int diag1 = -1;diag1<=1;diag1++){
            for(int diag2 = -1;diag2<=1;diag2++){
                int value = 0;
                if(c1 == c2) value = grid[row][c1];
                else value = grid[row][c1] + grid[row][c2];
                value += solve(row+1,c1+diag1,c2+diag2,grid,dp);
                maxi = max(maxi,value);
            }
        }
        return  dp[row][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};