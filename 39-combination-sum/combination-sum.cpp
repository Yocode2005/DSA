class Solution {
public:
    void findCombination(
        int idx,
        vector<int>& candidates,
        int target,
        vector<vector<int>>& ans,
        vector<int>& temp
    ) {
        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // No more candidates
        if (idx == candidates.size()) {
            return;
        }

        // Take current candidate
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);

            // idx remains same because we can reuse the candidate
            findCombination(
                idx,
                candidates,
                target - candidates[idx],
                ans,
                temp
            );

            temp.pop_back();
        }

        // Don't take current candidate
        findCombination(
            idx + 1,
            candidates,
            target,
            ans,
            temp
        );
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {
        vector<vector<int>> ans;
        vector<int> temp;

        findCombination(0, candidates, target, ans, temp);

        return ans;
    }
};