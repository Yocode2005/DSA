class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto time : times){
            int u  = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,k});
        vector<int>time(n+1,1e9);
        time[k] = 0;
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int nebNode = it.first;
                int wt = it.second;
                if(time[node] + wt < time[nebNode]){
                    time[nebNode] = time[node] + wt;
                    pq.push({time[nebNode],nebNode});
                }
            }
        }
        int ans = *max_element(time.begin() + 1, time.end());
        return ans == 1e9 ? -1 : ans;
    }
};