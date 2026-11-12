class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc = 1;   // current increasing subarray length
        int dec = 1;   // current decreasing subarray length
        int ans = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                // Increasing
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                // Decreasing
                dec++;
                inc = 1;
            }
            else {
                // Equal elements break both sequences
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};