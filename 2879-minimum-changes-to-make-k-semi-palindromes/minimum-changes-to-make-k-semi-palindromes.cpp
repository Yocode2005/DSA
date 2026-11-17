class Solution {
public:

    int minimumChanges(string s, int k) {

        int n = s.size();

        // cost[i][j] =
        // minimum changes required to make
        // substring s[i...j] a semi-palindrome
        vector<vector<int>> cost(
            n, vector<int>(n, 1e9)
        );

        // --------------------------------------------------
        // STEP 1: Calculate cost for every substring
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try every proper divisor d of len
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // There are d groups
                    for (int offset = 0;
                         offset < d;
                         offset++) {

                        int left = i + offset;

                        int right =
                            j - d + 1 + offset;

                        // Compare the group
                        // from both ends
                        while (left < right) {

                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] =
                        min(cost[i][j], changes);
                }
            }
        }

        // --------------------------------------------------
        // STEP 2: Partition the string into k parts
        // --------------------------------------------------

        // dp[i][j] =
        // minimum changes needed to divide
        // first i characters into j parts

        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, 1e9)
        );

        // 0 characters divided into 0 parts
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int parts = 1;
                 parts <= k;
                 parts++) {

                // h = starting point of last substring
                for (int h = 0;
                     h < i - 1;
                     h++) {

                    if (dp[h][parts - 1] == 1e9)
                        continue;

                    dp[i][parts] =
                        min(
                            dp[i][parts],
                            dp[h][parts - 1]
                            + cost[h][i - 1]
                        );
                }
            }
        }

        return dp[n][k];
    }
};