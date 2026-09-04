class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>minFromIndex(n);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = n-1;i>=0;i--){
             mini = min(mini,nums[i]);
             minFromIndex[i] = mini;
        }
        for(int it = 0;it<n;it++){
            maxi = max(maxi,nums[it]);
            if(maxi-minFromIndex[it]<=k){
                return it;
            }
        }
        return -1;
    }
};