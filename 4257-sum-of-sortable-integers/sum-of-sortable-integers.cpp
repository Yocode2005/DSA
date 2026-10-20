class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Prefix maximum
        vector<int> prefMax(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Step 2: Suffix minimum
        vector<int> suffMin(n + 1, INT_MAX);

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Step 3: Count adjacent descents
        vector<int> prefDrop(n, 0);

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] +
                          (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        // Step 4: Check every divisor k of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            // Divide the array into blocks of length k
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Count descents inside this block
                int drops = prefDrop[end] - prefDrop[start];

                // Include the circular boundary
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // Check if the block can be sorted by rotation
                if (drops > 1) {
                    valid = false;
                    break;
                }

                // Check whether this block can follow
                // the already processed prefix
                if (prefMax[start] > suffMin[start]) {
                    valid = false;
                    break;
                }
            }

            // Add k if it is sortable
            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};