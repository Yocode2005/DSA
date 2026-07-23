class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxIdx = 0;
       int n = nums.size();
       for(int i = 0;i<n;i++){
        if(i>maxIdx) return false;
        maxIdx = max(maxIdx, i + nums[i]);
       }
       return true;
    }
};