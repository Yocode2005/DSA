class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        int totalOnes = count(s.begin(), s.end(), '1');

        vector<bool> ans;

        for (string &str : strs) {

            int fixedOnes = count(str.begin(), str.end(), '1');
            int questions = count(str.begin(), str.end(), '?');

            // We need this many '?' to become '1'
            int need = totalOnes - fixedOnes;

            // Impossible to get the required number of 1s
            if (need < 0 || need > questions) {
                ans.push_back(false);
                continue;
            }

            /*
                Put the required 1s at the RIGHTMOST '?' positions.

                Why?

                Because 1 can only move towards the right
                after subsequence sorting.

                Putting 1s as far right as possible minimizes
                the number of 1s in every prefix.
            */
            int q = questions;

            for (int i = 0; i < n; i++) {
                if (str[i] == '?') {
                    q--;
                    if (need > q) {
                        str[i] = '1';
                        need--;
                    }
                    else {
                        str[i] = '0';
                    }
                }
            }

            // Check prefix condition
            int onesS = 0;
            int onesStr = 0;

            bool ok = true;

            for (int i = 0; i < n; i++) {

                if (s[i] == '1')
                    onesS++;

                if (str[i] == '1')
                    onesStr++;

                // Target cannot have more 1s
                // in a prefix than source.
                if (onesStr > onesS) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};