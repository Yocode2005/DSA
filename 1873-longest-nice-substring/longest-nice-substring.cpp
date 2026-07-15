class Solution {
public:
    string solve(string s){
        if(s.size()<2){
            return "";
        }
        unordered_set<char>st(s.begin(),s.end());
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(st.count(tolower(ch)) && st.count(toupper(ch))) continue;
            string left = solve(s.substr(0,i));
            string right = solve(s.substr(i+1));
            return (left.size() >= right.size()) ? left : right;
        }
        return s;
    }
    string longestNiceSubstring(string s) {
        return solve(s);
    }
};