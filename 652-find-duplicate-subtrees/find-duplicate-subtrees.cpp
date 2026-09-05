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
    string getSubTreeString(TreeNode*root,unordered_map<string,int> &mpp, vector<TreeNode*> &result){
        if(root == NULL){
            return "N";
        }
        string s = to_string(root->val) + "," + getSubTreeString(root->left,mpp,result) + "," + getSubTreeString(root->right,mpp,result);
        if(mpp[s] == 1){
            result.push_back(root);
        }
        mpp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mpp;
        vector<TreeNode*>result;
        getSubTreeString(root,mpp,result);
        return result;
    }
};