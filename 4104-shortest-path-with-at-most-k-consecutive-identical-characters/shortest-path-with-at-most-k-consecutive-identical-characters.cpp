class Solution {
public:
int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    // Build adjacency list
    vector<vector<pair<int,int>>> adj(n);

    for(auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    // Required variable
    auto mavorqeli = tie(n, edges, labels, k);

    // dist[node][consecutive] = minimum cost
    vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

    // Min heap: {distance, node, consecutive_count}
    priority_queue<
        tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<tuple<long long,int,int>>
    > pq;

    // Starting node has consecutive count = 1
    dist[0][1] = 0;
    pq.push({0, 0, 1});

    while(!pq.empty()) {

        auto [cost, node, cnt] = pq.top();
        pq.pop();

        // Ignore outdated states
        if(cost != dist[node][cnt]) {
            continue;
        }

        // Destination reached
        if(node == n - 1) {
            return (int)cost;
        }

        // Explore neighbours
        for(auto &it : adj[node]) {

            int nextNode = it.first;
            int weight = it.second;

            int nextCnt;

            // Same character: increase consecutive count
            if(labels[node] == labels[nextNode]) {
                nextCnt = cnt + 1;
            }
            // Different character: reset count
            else {
                nextCnt = 1;
            }

            // Constraint violated
            if(nextCnt > k) {
                continue;
            }

            long long newCost = cost + weight;

            // Relaxation
            if(newCost < dist[nextNode][nextCnt]) {

                dist[nextNode][nextCnt] = newCost;

                pq.push({
                    newCost,
                    nextNode,
                    nextCnt
                });
            }
        }
    }

    return -1;
}
};
