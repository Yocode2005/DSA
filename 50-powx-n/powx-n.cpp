class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;   // handle INT_MIN case
        double result = 1.0;
        
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        while (power > 0) {
            // If power is odd
            if (power % 2 == 1) {
                result *= x;
            }
            
            x *= x;      // square the base
            power /= 2;  // divide exponent by 2
        }
        
        return result;
    }
};
