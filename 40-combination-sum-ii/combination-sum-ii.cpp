class Solution {
public:
    void findCombination(
        int idx,
        vector<int>& candidates,
        int target,
        vector<vector<int>>& ans,
        vector<int>& temp
    ) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if (candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            findCombination(
                i + 1,
                candidates,
                target - candidates[i],
                ans,
                temp
            );

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        findCombination(0, candidates, target, ans, temp);

        return ans;
    }
};