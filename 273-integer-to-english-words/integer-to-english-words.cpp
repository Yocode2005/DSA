class Solution {
public:

    string oneToTwenty[20] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };

    string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string solve(int num) {

        if (num == 0)
            return "";

        if (num < 20)
            return oneToTwenty[num] + " ";

        if (num < 100)
            return tens[num / 10] + " " + solve(num % 10);

        return oneToTwenty[num / 100] + " Hundred " 
             + solve(num % 100);
    }

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        string ans = "";

        int billion = num / 1000000000;
        num %= 1000000000;

        int million = num / 1000000;
        num %= 1000000;

        int thousand = num / 1000;
        num %= 1000;

        int remainder = num;

        if (billion) {
            ans += solve(billion);
            ans += "Billion ";
        }

        if (million) {
            ans += solve(million);
            ans += "Million ";
        }

        if (thousand) {
            ans += solve(thousand);
            ans += "Thousand ";
        }

        if (remainder) {
            ans += solve(remainder);
        }

        // Remove trailing space
        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};