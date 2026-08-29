class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store indices
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Sort indices according to their values
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            // Find one connected group
            int j = i + 1;

            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> positions(idx.begin() + i, idx.begin() + j);

            // Smallest indices should receive smallest values
            sort(positions.begin(), positions.end());

            // Values are already sorted because idx is sorted
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};