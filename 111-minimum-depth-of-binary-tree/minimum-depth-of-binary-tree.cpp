/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode* root) {

        // empty tree
        if(root == NULL) {
            return 0;
        }

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }

        // if left subtree missing
        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // if right subtree missing
        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // both children exist
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};