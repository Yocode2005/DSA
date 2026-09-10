/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // returns {sum, count}
    pair<int, int> dfs(TreeNode* root, int& ans) {

        // Base case
        if (root == nullptr) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        auto left = dfs(root->left, ans);

        // Get sum and count from right subtree
        auto right = dfs(root->right, ans);

        // Calculate sum of current subtree
        int sum = root->val + left.first + right.first;

        // Calculate number of nodes in current subtree
        int count = 1 + left.second + right.second;

        // Check whether current node equals subtree average
        if (sum / count == root->val) {
            ans++;
        }

        // Return information to parent
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};