class Solution {
public:
    using ll = long long;

    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmll(long long a, long long b, long long limit) {
        long long g = gcdll(a, b);
        if (a > limit / (b / g))
            return limit + 1;
        return a / g * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = lcmll(l, coins[i], x);
                        if (l > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;

                if (__builtin_popcount(mask) & 1)
                    ans += x / l;
                else
                    ans -= x / l;
            }

            return ans;
        };

        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};