class Solution {
public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        unordered_map<int,int> factorCount = getFactorCount(primeCount);
        if (sumValues(factorCount) > (int)num.length())
            return construct(factorCount);

        unordered_map<int,int> primeCountPrefix = getPrimeCountFromStr(num);
        int firstZeroIndex = (int)num.find('0');
        if (firstZeroIndex == (int)string::npos) {
            firstZeroIndex = (int)num.length();
            if (isSubset(primeCount, primeCountPrefix))
                return num;
        }

        for (int i = (int)num.length() - 1; i >= 0; --i) {
            int d = num[i] - '0';
            primeCountPrefix = subtract(primeCountPrefix, factorsOf(d));
            int spaceAfterThisDigit = (int)num.length() - 1 - i;
            if (i > firstZeroIndex) continue;
            for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
                unordered_map<int,int> factorsAfterReplacement =
                    getFactorCount(subtract(subtract(primeCount, primeCountPrefix), factorsOf(biggerDigit)));
                int need = sumValues(factorsAfterReplacement);
                if (need <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - need;
                    return num.substr(0, i) + to_string(biggerDigit) +
                           string(fillOnes, '1') + construct(factorsAfterReplacement);
                }
            }
        }

        unordered_map<int,int> factorsAfterExtension = getFactorCount(primeCount);
        return string(num.length() + 1 - sumValues(factorsAfterExtension), '1') +
               construct(factorsAfterExtension);
    }

private:
    // Prime-factor breakdown of each digit 0..9 (only digits 2..9 have entries).
    static const unordered_map<int,int>& factorsOf(int d) {
        static const unordered_map<int, unordered_map<int,int>> table = {
            {0, {}}, {1, {}},
            {2, {{2,1}}},
            {3, {{3,1}}},
            {4, {{2,2}}},
            {5, {{5,1}}},
            {6, {{2,1},{3,1}}},
            {7, {{7,1}}},
            {8, {{2,3}}},
            {9, {{3,2}}}
        };
        return table.at(d);
    }

    // Factorize t into 2^a * 3^b * 5^c * 7^d; returns (counts, whether t becomes 1).
    pair<unordered_map<int,int>, bool> getPrimeCount(long long t) {
        unordered_map<int,int> count{{2,0},{3,0},{5,0},{7,0}};
        for (int prime : {2,3,5,7})
            while (t % prime == 0) { t /= prime; ++count[prime]; }
        return {count, t == 1};
    }

    // Prime-factor counts contributed by the digits of num.
    unordered_map<int,int> getPrimeCountFromStr(const string& num) {
        unordered_map<int,int> count{{2,0},{3,0},{5,0},{7,0}};
        for (char c : num)
            for (auto& [prime, freq] : factorsOf(c - '0'))
                count[prime] += freq;
        return count;
    }

    // Given required prime factor counts, find the minimal digit multiset
    // (each 2..9) that supplies them, preferring fewer/larger digits.
    unordered_map<int,int> getFactorCount(const unordered_map<int,int>& count) {
        int c2 = count.count(2) ? count.at(2) : 0;
        int c3 = count.count(3) ? count.at(3) : 0;
        int c5 = count.count(5) ? count.at(5) : 0;
        int c7 = count.count(7) ? count.at(7) : 0;

        int count8 = c2 / 3;
        int remaining2 = c2 % 3;
        int count9 = c3 / 2;
        int count3 = c3 % 2;
        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;
        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0; count3 = 0; count6 = 1;
        }
        if (count3 == 1 && count4 == 1) {
            count2 = 1; count6 = 1; count3 = 0; count4 = 0;
        }

        return unordered_map<int,int>{
            {2,count2},{3,count3},{4,count4},{5,c5},
            {6,count6},{7,c7},{8,count8},{9,count9}
        };
    }

    string construct(const unordered_map<int,int>& factors) {
        string res;
        for (int digit = 2; digit < 10; ++digit) {
            auto it = factors.find(digit);
            if (it != factors.end())
                res += string(it->second, char('0' + digit));
        }
        return res;
    }

    bool isSubset(const unordered_map<int,int>& a, const unordered_map<int,int>& b) {
        for (auto& [key, value] : a) {
            int bv = b.count(key) ? b.at(key) : 0;
            if (bv < value) return false;
        }
        return true;
    }

    unordered_map<int,int> subtract(unordered_map<int,int> a, const unordered_map<int,int>& b) {
        for (auto& [key, value] : b)
            a[key] = max(0, (a.count(key) ? a[key] : 0) - value);
        return a;
    }

    int sumValues(const unordered_map<int,int>& count) {
        int s = 0;
        for (auto& [k, v] : count) s += v;
        return s;
    }
};