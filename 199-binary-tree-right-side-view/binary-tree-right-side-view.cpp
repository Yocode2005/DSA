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
    // int levels(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return 1+max(levels(root->left),levels(root->right));
    // }
    // void preOrder(TreeNode* root,vector<int> &ans, int level){
    //     if(root == NULL) return;
    //     ans[level] = root->val;
    //     preOrder(root->left,ans,level+1);
    //     preOrder(root->right,ans,level+1);
    // }

    void rightView(TreeNode* root, int level, vector<int> & ans){
        if(root == NULL) return; 
        if(ans.size() == level) ans.push_back(root->val);
        rightView(root->right, level+1, ans);
        rightView(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> ans(levels(root),0);
        // preOrder(root,ans,0);
        // return ans;

        vector<int>ans;
        rightView(root,0,ans);
        return ans;
    }
};