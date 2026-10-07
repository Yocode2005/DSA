class Solution {
public:

    set<string> ans;

    // Check whether the string is valid
    bool isValid(string &s) {

        int balance = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                balance--;

                // More ')' than '('
                if (balance < 0)
                    return false;
            }
        }

        // All '(' must have a matching ')'
        return balance == 0;
    }


    void solve(string &s, int index, int leftRemove, int rightRemove) {

        // No removals left
        if (leftRemove == 0 && rightRemove == 0) {

            if (isValid(s)) {
                ans.insert(s);
            }

            return;
        }


        // We have processed the whole string
        if (index >= s.size())
            return;


        // Try removing current character
        if (s[index] == '(' && leftRemove > 0) {

            string temp = s;

            temp.erase(index, 1);

            solve(temp, index, leftRemove - 1, rightRemove);
        }


        if (s[index] == ')' && rightRemove > 0) {

            string temp = s;

            temp.erase(index, 1);

            solve(temp, index, leftRemove, rightRemove - 1);
        }


        // Keep current character
        solve(s, index + 1, leftRemove, rightRemove);
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        solve(s, 0, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};