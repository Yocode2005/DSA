class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int it = 0;it<=i;it++){ // find max element 
                maxi = max(maxi,nums[it]);
            }
            for(int idx = i;idx<n;idx++){// find min element
                mini = min(mini,nums[idx]);
            }
            if(maxi-mini<=k){
                return i;
            }
        }
        return -1;
    }
};