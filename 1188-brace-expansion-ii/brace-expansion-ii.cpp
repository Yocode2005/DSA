class Solution {
public:

    // Parse an expression containing UNION (,)
    set<string> parseExpression(string &s, int &i) {

        // First parse one concatenated part
        set<string> result = parseTerm(s, i);

        // Handle UNION
        while (i < s.size() && s[i] == ',') {

            i++; // skip ','

            set<string> next = parseTerm(s, i);

            // Union of result and next
            result.insert(next.begin(), next.end());
        }

        return result;
    }


    // Parse concatenation
    set<string> parseTerm(string &s, int &i) {

        // Empty string initially
        set<string> result;
        result.insert("");

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> part;

            // If we encounter {
            if (s[i] == '{') {

                i++; // skip '{'

                // Parse everything inside {}
                part = parseExpression(s, i);

                i++; // skip '}'
            }

            // Normal character
            else {

                part.insert(string(1, s[i]));

                i++;
            }

            // Concatenate result with part
            set<string> temp;

            for (string a : result) {
                for (string b : part) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};