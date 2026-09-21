class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at the
        // previous index whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {

            vector<long long> newDp(k, 0);

            // Start a new subarray with only nums[i]
            int rem = num % k;
            newDp[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                
                if (dp[r] == 0)
                    continue;

                int newRem = (r * rem) % k;

                newDp[newRem] += dp[r];
            }

            // Add all subarrays ending at current index
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};