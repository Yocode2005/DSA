class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(string str) {
        // Leading zero is invalid for multi-digit numbers
        if (str.length() > 1 && str[0] == '0') {
            return false;
        }

        int val = stoi(str);

        return val <= 255;
    }

    void solve(string &s, int idx, int parts, string curr) {

        // We have used all characters and created 4 parts
        if (idx == n && parts == 4) {
            curr.pop_back(); // remove last '.'
            result.push_back(curr);
            return;
        }

        // More than 4 parts
        if (parts >= 4) {
            return;
        }

        // 1 digit
        if (idx < n) {
            string part = s.substr(idx, 1);

            if (isValid(part)) {
                solve(s, idx + 1, parts + 1,
                      curr + part + ".");
            }
        }

        // 2 digits
        if (idx + 2 <= n) {
            string part = s.substr(idx, 2);

            if (isValid(part)) {
                solve(s, idx + 2, parts + 1,
                      curr + part + ".");
            }
        }

        // 3 digits
        if (idx + 3 <= n) {
            string part = s.substr(idx, 3);

            if (isValid(part)) {
                solve(s, idx + 3, parts + 1,
                      curr + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        result.clear();

        if (n < 4 || n > 12) {
            return {};
        }

        solve(s, 0, 0, "");

        return result;
    }
};