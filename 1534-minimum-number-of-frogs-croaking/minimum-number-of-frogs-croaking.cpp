class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> cnt(5, 0);
        int frogs = 0, ans = 0;

        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                cnt[0]++;
                frogs++;
                ans = max(ans, frogs);
            }
            else if (ch == 'r') {
                if (cnt[0] == 0) return -1;
                cnt[0]--;
                cnt[1]++;
            }
            else if (ch == 'o') {
                if (cnt[1] == 0) return -1;
                cnt[1]--;
                cnt[2]++;
            }
            else if (ch == 'a') {
                if (cnt[2] == 0) return -1;
                cnt[2]--;
                cnt[3]++;
            }
            else { // 'k'
                if (cnt[3] == 0) return -1;
                cnt[3]--;
                frogs--;
            }
        }

        if (frogs != 0) return -1;

        return ans;
    }
};