class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // {enqueueTime, processingTime, originalIndex}
        vector<vector<int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(arr.begin(), arr.end());

        // {processingTime, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            // If no task is available, jump to the next enqueue time
            if (pq.empty() && time < arr[i][0]) {
                time = arr[i][0];
            }

            // Push all tasks that have arrived
            while (i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            // Execute the shortest job
            auto curr = pq.top();
            pq.pop();

            int processTime = curr.first;
            int index = curr.second;

            ans.push_back(index);
            time += processTime;
        }

        return ans;
    }
};