class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int totalSum = 0;

        // Store prefix sum -> earliest index
        unordered_map<int, int> mpp;

        // Prefix sum 0 exists before index 0
        mpp[0] = -1;

        for (int i = 0; i < n; i++) {

            totalSum += nums[i];

            // Store only the first occurrence
            if (mpp.find(totalSum) == mpp.end()) {
                mpp[totalSum] = i;
            }
        }

        // We need to keep a subarray whose sum is totalSum - x
        int remainingSum = totalSum - x;

        int longestSubArray = -1;

        int prefixSum = 0;

        for (int i = 0; i < n; i++) {

            prefixSum += nums[i];

            // We need:
            // prefixSum - previousPrefix = remainingSum
            //
            // Therefore:
            // previousPrefix = prefixSum - remainingSum

            int findSum = prefixSum - remainingSum;

            if (mpp.find(findSum) != mpp.end()) {

                int idx = mpp[findSum];

                int length = i - idx;

                longestSubArray = max(longestSubArray, length);
            }
        }

        // No valid subarray
        if (longestSubArray == -1) {
            return -1;
        }

        // Remove everything outside the longest subarray
        return n - longestSubArray;
    }
};