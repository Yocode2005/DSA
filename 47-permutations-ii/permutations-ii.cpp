class Solution {
public:
    void getpermo(int idx, vector<int>& nums,
               vector<vector<int>>& ans) {

        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = idx; i < nums.size(); i++) {

            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[idx], nums[i]);
            getpermo(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermo(0, nums, ans);
        return ans;
    }
};