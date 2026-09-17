class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {

            // Add current element to window
            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // If current window has target sum
            if (sum == target) {

                int len = right - left + 1;

                // Check if there is a previous non-overlapping
                // subarray before 'left'
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store the minimum valid subarray length
                // ending at or before 'right'
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }

            } else {

                // No valid subarray ending at right,
                // so carry forward previous best
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};