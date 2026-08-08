class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = earliest? Actually, while scanning from right,
        // it stores the position in word1 that can match word2[j]
        // while keeping the remaining suffix of word2 possible.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Build suffix matching information.
        //
        // last[j] = position in word1 where word2[j] can be matched,
        // such that word2[j+1 ... m-1] can still be matched after it.
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // We can use our one allowed mismatch only once.
        bool canMismatch = true;

        j = 0;

        // Greedily choose the smallest possible index.
        for (i = 0; i < n && j < m; i++) {

            // Best case: current character already matches.
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Otherwise, try to use the one allowed mismatch.
            else if (canMismatch) {

                // If this is the last character of word2,
                // we can safely use the mismatch.
                //
                // Otherwise, after taking i as the mismatch,
                // we must still be able to match word2[j+1...].
                if (j == m - 1 || i < last[j + 1]) {
                    ans[j] = i;
                    j++;
                    canMismatch = false;
                }
            }
        }

        // We couldn't construct the complete sequence.
        if (j != m)
            return {};

        return ans;
    }
};