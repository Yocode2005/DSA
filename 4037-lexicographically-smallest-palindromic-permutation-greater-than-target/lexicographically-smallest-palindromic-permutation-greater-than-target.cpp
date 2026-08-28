class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Frequency of characters
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // More than one odd frequency -> impossible
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Only half of every frequency is needed
        // for constructing the left half.
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int half = n / 2;

        // ans will store the left half
        string ans(n, 'a');

        int pos = 0;

        // Try to make the left half equal to target
        while (pos < half) {

            int c = target[pos] - 'a';

            if (freq[c] == 0) {
                break;
            }

            ans[pos] = target[pos];
            freq[c]--;

            pos++;
        }

        // Construct the complete palindrome
        auto makePalindrome = [&]() {

            if (mid != -1) {
                ans[half] = char('a' + mid);
            }

            for (int i = 0; i < half; i++) {
                ans[n - 1 - i] = ans[i];
            }
        };

        // The entire left half matched target
        if (pos == half) {

            makePalindrome();

            if (ans > target) {
                return ans;
            }
        }

        /*
            We couldn't get a palindrome greater than target
            with the current prefix.

            Move backwards and try to increase a position.
        */
        while (true) {

            // Try to make current position larger
            if (pos < half) {

                int need = target[pos] - 'a' + 1;

                for (int c = need; c < 26; c++) {

                    if (freq[c] > 0) {

                        // Put this character
                        ans[pos] = char('a' + c);
                        freq[c]--;

                        // Fill remaining positions
                        // with smallest available chars.
                        int idx = pos + 1;

                        for (int x = 0; x < 26; x++) {

                            while (freq[x] > 0) {
                                ans[idx++] = char('a' + x);
                                freq[x]--;
                            }
                        }

                        // Make palindrome
                        makePalindrome();

                        return ans;
                    }
                }
            }

            // Cannot increase this position.
            // Move one position backwards.
            if (pos == 0) {
                return "";
            }

            pos--;

            // Restore the character that was equal
            // to target[pos].
            freq[target[pos] - 'a']++;
        }
    }
};