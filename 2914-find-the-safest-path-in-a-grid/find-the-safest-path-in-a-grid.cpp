class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(newRow >= 0 && newRow<n && newCol >= 0 && newCol < m && dist[newRow][newCol] == 1e9){
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow,newCol});
                }
            }
        }
         // Max Heap
        priority_queue<pair<int,pair<int,int>>> pq;

        vector<vector<int>> best(n, vector<int>(m,-1));

        pq.push({dist[0][0],{0,0}});

        best[0][0]=dist[0][0];

        while(!pq.empty()){

            auto curr=pq.top();
            pq.pop();

            int safe=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;

            if(row==n-1 && col==n-1)
                return safe;

            for(int i=0;i<4;i++){

                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<n){

                    int newSafe=min(safe,dist[nr][nc]);

                    if(newSafe>best[nr][nc]){

                        best[nr][nc]=newSafe;
                        pq.push({newSafe,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};