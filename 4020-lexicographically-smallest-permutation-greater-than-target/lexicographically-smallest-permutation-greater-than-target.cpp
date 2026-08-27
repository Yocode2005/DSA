class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // left[c] = count in s - count used by target prefix
        vector<int> left(26, 0);

        for (int i = 0; i < n; i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        // Try changing target[i] into a larger character.
        for (int i = n - 1; i >= 0; i--) {

            // Undo the use of target[i].
            left[target[i] - 'a']++;

            // Check whether target[0 ... i-1]
            // can actually be constructed.
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (left[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find the smallest available character
            // greater than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (left[c] == 0)
                    continue;

                // Use this larger character.
                left[c]--;

                string ans = target.substr(0, i);

                ans += char('a' + c);

                // Fill the remaining suffix with the
                // smallest possible characters.
                for (int k = 0; k < 26; k++) {
                    while (left[k] > 0) {
                        ans += char('a' + k);
                        left[k]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};