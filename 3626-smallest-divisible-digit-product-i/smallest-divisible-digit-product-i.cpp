class Solution {
public:
    int smallestNumber(int n, int t) {
        int number = n;
        while(true){
            int product = 1;
            n = number;
            while(n){
                product  *= n%10;
                n /= 10;
            }
            if(product%t == 0) break;
            else number++;
        }
        return number;
    }
};