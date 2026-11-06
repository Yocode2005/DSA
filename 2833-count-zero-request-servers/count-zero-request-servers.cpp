class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        auto lamda = [](vector<int>& vec1, vector<int>& vec2){
            return vec1[1]<vec2[1];// sort on basis os the time in ascending order
        };
        sort(begin(logs),end(logs),lamda);

        int q = queries.size();
        vector<int> result(q);

        vector<pair<int,int>>timeIndex(q); // {time, originalIdx}
        for(int i = 0;i<q;i++){
            timeIndex[i] = {queries[i],i};
        }
        sort(begin(timeIndex),end(timeIndex));

        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        for(auto [time,idx] : timeIndex){
            int start = time-x;
            int end = time;

            while(j<m && logs[j][1] <= end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<m && logs[i][1] < start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            result[idx] = n-mp.size();
        }
        return result;
    }
};