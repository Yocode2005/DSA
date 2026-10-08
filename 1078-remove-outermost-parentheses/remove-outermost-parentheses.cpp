class Solution {
public:
    string removeOuterParentheses(string s) {
          string result = "";  
        // Initialize nesting level counter
        int level = 0;       

        // Traverse the string
        for (char ch : s) {
            // If we encounter '(', increase the level
            if (ch == '(') {
                // If we're inside a primitive, add '(' to result
                if (level > 0) result += ch;
                // Increase the nesting level for '('
                level++;  
            } 
            // If we encounter ')', decrease the level
            else if (ch == ')') {
                // Decrease the nesting level for ')'
                level--;  
                // If we're inside a primitive, add ')' to result
                if (level > 0) result += ch;
            }
        }
         return result;
    }
};