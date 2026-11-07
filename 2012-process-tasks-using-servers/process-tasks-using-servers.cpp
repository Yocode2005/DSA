class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();

        // {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // {finishTime, weight, index}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busy;

        // Initially, all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            // Current task arrives at time i
            time = max(time, (long long)i);

            // Move all servers that have finished
            // by the current time into available
            while (!busy.empty() && get<0>(busy.top()) <= time) {

                auto [finishTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available,
            // jump time to the earliest finishing server
            if (available.empty()) {

                time = get<0>(busy.top());

                // Move all servers finishing at this time
                while (!busy.empty() && get<0>(busy.top()) <= time) {

                    auto [finishTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            // Assign task i to this server
            ans.push_back(index);

            // Server becomes free after processing the task
            long long finishTime = time + tasks[i];

            busy.push({finishTime, weight, index});
        }

        return ans;
    }
};