class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;
        for (char ch : s) {
            rows[currentRow] += ch;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }
        string ans;
        for (string &row : rows)
            ans += row;
        return ans;
    }
};