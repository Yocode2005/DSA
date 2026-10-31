class Solution {
public:
int solve(vector<int>& nums,int target,int idx, int currentSum){
    if(idx == nums.size()){
        if(currentSum == target) return 1;
        return 0;
    }
    int positive = solve(nums,target,idx+1,currentSum+nums[idx]);
    int negative = solve(nums,target,idx+1,currentSum-nums[idx]);
    return positive+negative;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return solve(nums,target,0,0);
}
};
