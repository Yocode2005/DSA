class Solution {
public:
    int n;
    unordered_map<long long, bool> dp;

    bool f(int idx, int jump, vector<int>& stones,
           unordered_map<int, int>& pos) {

        if (idx == n - 1)
            return true;

        long long key = ((long long)idx << 32) | jump;

        if (dp.count(key))
            return dp[key];

        for (int nextJump = jump - 1;
             nextJump <= jump + 1;
             nextJump++) {

            if (nextJump <= 0)
                continue;

            int nextPosition = stones[idx] + nextJump;

            if (pos.count(nextPosition)) {
                int nextIdx = pos[nextPosition];

                if (f(nextIdx, nextJump, stones, pos))
                    return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        // First jump must be exactly 1.
        if (stones[1] != 1)
            return false;

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        return f(1, 1, stones, pos);
    }
};