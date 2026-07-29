class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<int> result;

        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] + nums[j] == target) {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }

        // return result;

        vector<int>ans;
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){
            int remaining = target-nums[i];
            if(m.find(remaining) != m.end()){
                ans.push_back(m[remaining]);
                ans.push_back(i);
            }
            else m[nums[i]] = i;
        }
        return ans;
    }
};
