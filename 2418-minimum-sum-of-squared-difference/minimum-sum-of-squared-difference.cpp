class Solution {
public:
long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
long long k = (long long)k1 + k2;
vector<int> freq(100001, 0);
    long long sum = 0;

    // Calculate absolute differences and their frequencies
    for (int i = 0; i < nums1.size(); i++) {
        int d = abs(nums1[i] - nums2[i]);
        freq[d]++;
        sum += d;
    }

    // If all differences can be reduced to zero
    if (sum <= k) {
        return 0;
    }

    // Reduce the largest differences first
    for (int d = 100000; d > 0 && k > 0; d--) {
        if (freq[d] == 0) {
            continue;
        }

        long long count = freq[d];
        long long operations = min(k, count);

        freq[d] -= operations;
        freq[d - 1] += operations;

        k -= operations;
    }

    // Calculate the final sum of squared differences
    long long ans = 0;

    for (int d = 1; d <= 100000; d++) {
        ans += 1LL * d * d * freq[d];
    }

    return ans;
}
};
