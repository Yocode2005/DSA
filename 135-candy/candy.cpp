class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> ans(n, 1);

        // Left to Right
        for (int i = 1; i < n; i++) {
            if (rating[i] > rating[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }

        // Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (rating[i] > rating[i + 1] && ans[i] <= ans[i + 1]) {
                ans[i] = ans[i + 1] + 1;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += ans[i];
        }

        return count;
    }
};