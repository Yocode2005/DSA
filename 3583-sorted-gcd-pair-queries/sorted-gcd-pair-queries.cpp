#include <vector>
#include <algorithm>
using namespace std;

// Helper function to compute GCD
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);

        // Count frequency of each number
        for (int x : nums) freq[x]++;

        // Count pairs for each possible GCD
        vector<long long> count(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; ++g) {
            long long cnt = 0;
            // Count numbers divisible by g
            for (int k = g; k <= maxVal; k += g) {
                cnt += freq[k];
            }
            // Number of pairs (i < j) with GCD g: C(cnt, 2)
            count[g] = cnt * (cnt - 1) / 2;
        }

        // Inclusion-Exclusion: subtract pairs counted for multiples
        for (int g = maxVal; g >= 1; --g) {
            for (int k = 2 * g; k <= maxVal; k += g) {
                count[g] -= count[k];
            }
        }

        // Build sorted GCD pairs array (not explicitly, just prefix sums)
        vector<pair<long long, int>> prefix; // (ending index, gcd value)
        long long idx = 0;
        for (int g = 1; g <= maxVal; ++g) {
            if (count[g] > 0) {
                idx += count[g];
                prefix.push_back({idx, g});
            }
        }

        // Answer queries using binary search
        vector<int> res;
        for (auto q : queries) {
            // Find the smallest prefix index >= q+1
            auto it = lower_bound(prefix.begin(), prefix.end(), make_pair(q + 1, 0));
            res.push_back(it->second);
        }
        return res;
    }
};