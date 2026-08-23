class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int i = prices.size() - 1;
        int j = discounts.size() - 1;

        double ans = 0.0;

        // Apply largest discount to largest price
        while (i >= 0 && j >= 0) {
            ans += (double)prices[i] * (100 - discounts[j]) / 100.0;

            i--;
            j--;
        }

        // Remaining prices don't get any discount
        while (i >= 0) {
            ans += prices[i];
            i--;
        }

        return ans;
    }
};