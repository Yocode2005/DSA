class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by start time
        sort(intervals.begin(), intervals.end());

        // next[i] = first interval whose start > intervals[i].end
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];

            next[i] = upper_bound(
                intervals.begin() + i + 1,
                intervals.end(),
                end,
                [](int value, const vector<int>& v) {
                    return value < v[0];
                }
            ) - intervals.begin();
        }

        /*
            dp[i][k] = maximum score we can get
            from interval i onward,
            if we can still select k intervals.

            We only store SCORE here.
            We don't store vectors, which avoids TLE.
        */
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Don't take current interval
                long long skip = dp[i + 1][k];

                // Take current interval
                long long take =
                    intervals[i][2] +
                    dp[next[i]][k - 1];

                dp[i][k] = max(skip, take);
            }
        }

        /*
            Now reconstruct the answer.

            We always choose the lexicographically smaller
            answer when both choices give the same score.
        */

        vector<int> ans;

        int i = 0;
        int k = 4;

        while (i < n && k > 0) {

            long long skip = dp[i + 1][k];

            long long take =
                intervals[i][2] +
                dp[next[i]][k - 1];

            if (take > skip) {

                // Take this interval
                ans.push_back(intervals[i][3]);

                i = next[i];
                k--;

            } else if (take < skip) {

                // Skip this interval
                i++;

            } else {

                /*
                    Both choices give the same score.

                    We need lexicographically smallest
                    original-index list.

                    Since the current interval has the
                    smallest start among remaining intervals,
                    we cannot simply compare its original
                    index with the skip case.

                    We therefore determine the answer for
                    both choices using a separate comparison.
                */

                // In a tie, compare the original index of
                // current interval with the first selected
                // index obtainable by skipping it.

                vector<int> takeAns;
                vector<int> skipAns;

                // Build take answer
                int ti = next[i];
                int tk = k - 1;

                takeAns.push_back(intervals[i][3]);

                while (ti < n && tk > 0) {
                    long long s = dp[ti + 1][tk];
                    long long t =
                        intervals[ti][2] +
                        dp[next[ti]][tk - 1];

                    if (t >= s) {
                        takeAns.push_back(intervals[ti][3]);
                        ti = next[ti];
                        tk--;
                    } else {
                        ti++;
                    }
                }

                // Build skip answer
                int si = i + 1;
                int sk = k;

                while (si < n && sk > 0) {
                    long long s = dp[si + 1][sk];
                    long long t =
                        intervals[si][2] +
                        dp[next[si]][sk - 1];

                    if (t >= s) {
                        skipAns.push_back(intervals[si][3]);
                        si = next[si];
                        sk--;
                    } else {
                        si++;
                    }
                }

                sort(takeAns.begin(), takeAns.end());
                sort(skipAns.begin(), skipAns.end());

                if (takeAns < skipAns) {
                    ans.insert(ans.end(), takeAns.begin(), takeAns.end());
                } else {
                    ans.insert(ans.end(), skipAns.begin(), skipAns.end());
                }

                break;
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};