class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // score of the current level

        for (char ch : s) {
            if (ch == '(') {
                st.push(0);
            } 
            else {
                int inner = st.top();
                st.pop();

                int score;

                if (inner == 0) {
                    // "()"
                    score = 1;
                } 
                else {
                    // "(A)"
                    score = 2 * inner;
                }

                // Add this group's score to its parent level
                st.top() += score;
            }
        }

        return st.top();
    }
};