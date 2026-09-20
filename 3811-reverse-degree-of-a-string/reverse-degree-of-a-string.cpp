class Solution {
public:
    int reverseDegree(string s) {

        int n = s.length();
        int sum = 0;

        int start = 26;
        unordered_map<char, int> mpp;

        // Store reverse degree of each character
        for (char ch = 'a'; ch <= 'z'; ch++) {
            mpp[ch] = start;
            start--;
        }

        // Traverse the string
        for (int i = 0; i < n; i++) {

            if (mpp.find(s[i]) != mpp.end()) {

                int value = mpp[s[i]];

                // Position is 1-based
                sum += value * (i + 1);
            }
        }

        return sum;
    }
};