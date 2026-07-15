class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = 0;i<=2*n;i++){
            if(i%2 != 0) sumOdd += i;
            sumEven += i;
        }
        int maxSum = max(sumOdd,sumEven);
        int ans;
        while(maxSum>0){
            if((sumOdd%maxSum == 0 ) && (sumEven%maxSum == 0)){
                ans = maxSum;
                break;
            }
            maxSum--;
        }
        return ans;
    }
};