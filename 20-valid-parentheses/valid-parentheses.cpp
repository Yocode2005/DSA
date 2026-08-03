class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> ch;
        for(int i = 0;i<n;i++){
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
                ch.push(s[i]);
            }
            else {
                if(ch.size() == 0) return false;
                if((s[i] == ')' && ch.top() == '(') ||
                   (s[i] == '}' && ch.top() == '{') ||
                   (s[i] == ']' && ch.top() == '[')) {
                    ch.pop();
                }
                else {
                    return false;
                }
            }

        }
        return ch.empty();
    }
};