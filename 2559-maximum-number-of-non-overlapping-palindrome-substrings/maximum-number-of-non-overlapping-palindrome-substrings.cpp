class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes we can take
        // from index i to n-1
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Option 1: skip current character
            dp[i] = dp[i + 1];

            // Option 2: take a palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (pal[i][j]) {
                    dp[i] = max(dp[i],
                                1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};