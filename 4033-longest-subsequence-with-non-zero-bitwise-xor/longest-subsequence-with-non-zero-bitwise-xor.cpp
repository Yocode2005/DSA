class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        int totalXOR = 0;
        bool hasNonZero = false;

        // Calculate XOR of the complete array
        for (int x : nums) {

            totalXOR ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Case 1:
        // Entire array already has non-zero XOR
        if (totalXOR != 0) {
            return n;
        }

        // Case 2:
        // Total XOR is 0, but at least one element is non-zero.
        // Remove that non-zero element.
        if (hasNonZero) {
            return n - 1;
        }

        // Case 3:
        // All elements are zero.
        return 0;
    }
};