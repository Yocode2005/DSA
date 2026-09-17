class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0;i<n;i++){
            totalSum += nums[i];
        }
        if(totalSum%2 != 0){
            return 0;
        }
          return n - 1;
    }
};