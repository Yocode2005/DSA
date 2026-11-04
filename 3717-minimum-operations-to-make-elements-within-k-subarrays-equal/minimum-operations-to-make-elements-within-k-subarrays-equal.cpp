
class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    unordered_map<int, int> delayed;

    long long smallSum = 0, largeSum = 0;

    int smallSize = 0, largeSize = 0;

    void pruneSmall() {
        while (!small.empty() && delayed[small.top()] > 0) {
            delayed[small.top()]--;
            small.pop();
        }
    }

    void pruneLarge() {
        while (!large.empty() && delayed[large.top()] > 0) {
            delayed[large.top()]--;
            large.pop();
        }
    }

    void rebalance() {

        int target = (smallSize + largeSize + 1) / 2;

        while (smallSize > target) {

            pruneSmall();

            int val = small.top();
            small.pop();

            large.push(val);

            smallSum -= val;
            largeSum += val;

            smallSize--;
            largeSize++;
        }

        while (smallSize < target) {

            pruneLarge();

            int val = large.top();
            large.pop();

            small.push(val);

            largeSum -= val;
            smallSum += val;

            smallSize++;
            largeSize--;
        }

        pruneSmall();
        pruneLarge();
    }

    void add(int val) {

        pruneSmall();

        if (small.empty() || val <= small.top()) {
            small.push(val);
            smallSum += val;
            smallSize++;
        }
        else {
            large.push(val);
            largeSum += val;
            largeSize++;
        }

        rebalance();
    }

    void remove(int val) {

        pruneSmall();
        pruneLarge();

        delayed[val]++;

        if (val <= small.top()) {
            smallSum -= val;
            smallSize--;

            if (val == small.top())
                pruneSmall();
        }
        else {
            largeSum -= val;
            largeSize--;

            if (!large.empty() && val == large.top())
                pruneLarge();
        }

        rebalance();
    }

    long long getCost() {

        pruneSmall();

        long long median = small.top();

        return median * smallSize - smallSum
             + largeSum - median * largeSize;
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        vector<long long> cost;

        // Step 1: Calculate cost of every window

        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x)
                remove(nums[i - x]);

            if (i >= x - 1)
                cost.push_back(getCost());
        }

        // Step 2: DP

        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select window ending at i-1
                if (i >= x && prev[i - x] != INF) {

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
