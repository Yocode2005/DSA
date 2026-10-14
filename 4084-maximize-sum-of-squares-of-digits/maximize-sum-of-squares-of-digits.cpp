class Solution {
public:
string maxSumOfSquares(int num, int sum) {
// If the required sum exceeds the maximum possible sum
if (sum > 9 * num) {
return "";
}
    // Number of 9s we can use
    int nines = sum / 9;

    // Remaining sum after using all possible 9s
    int remainder = sum % 9;

    // Place all 9s at the beginning
    string ans(nines, '9');

    // Add the remaining digit if it is non-zero
    if (remainder > 0) {
        ans += char('0' + remainder);
    }

    // Fill the remaining positions with zeros
    ans += string(num - ans.size(), '0');

    return ans;
}

};
