class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        // powers[i] = 2^i
        vector<int> powers(n);

        powers[0] = 1;

        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2LL) % MOD;
        }

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {

                // nums[left] must be included.
                // Every element between left and right
                // can either be picked or not picked.
                //
                // Number of choices = 2^(right-left)
                ans = (ans + powers[right - left]) % MOD;

                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};