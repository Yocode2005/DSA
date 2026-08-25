class Solution {
public:
int rob1(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n ==1) return nums[0];
      vector<int>temp1;
      vector<int>temp2;
      for(int i = 0;i<n;i++){
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
      } 
      return max(rob1(temp1),rob1(temp2));
    }
};