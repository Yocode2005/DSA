class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size() - 1; i >= 0; i--) {
            
            if(digits[i] < 9) {
                digits[i]++;        // add 1
                return digits;      // no carry needed
            }
            
            digits[i] = 0;          // if digit is 9
        }
        
        // if all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};