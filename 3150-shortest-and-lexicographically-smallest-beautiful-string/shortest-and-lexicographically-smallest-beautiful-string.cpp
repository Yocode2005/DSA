class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        for (int len = k; len <= n; len++) {

            string result = "";

            for (int start = 0; start <= n - len; start++) {

                string temp = s.substr(start, len);

                int cnt = count(temp.begin(), temp.end(), '1');

                if (cnt == k) {

                    if (result.empty() || temp < result) {
                        result = temp;
                    }
                }
            }

            // First valid length = shortest length
            if (!result.empty()) {
                return result;
            }
        }

        return "";
    }
};