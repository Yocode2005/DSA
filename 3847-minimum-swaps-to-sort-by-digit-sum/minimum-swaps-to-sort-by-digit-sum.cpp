class Solution {
public:
    // Calculate the sum of digits of a number
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store {digit sum, number, original index}
        vector<array<int, 3>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i], i});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];

                 return a[1] < b[1];
             });

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;

                // Move to the original index of this element
                j = arr[j][2];
            }

            // A cycle of size k requires k - 1 swaps
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};