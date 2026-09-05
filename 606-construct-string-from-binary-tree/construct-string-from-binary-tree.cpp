class Solution {
public:
    void traverse(TreeNode* root, string &ans) {

        if (root == NULL)
            return;

        // Add current node
        ans += to_string(root->val);

        // If left child exists
        if (root->left != NULL) {
            ans += "(";
            traverse(root->left, ans);
            ans += ")";
        }

        // If right child exists
        if (root->right != NULL) {
            // If there is no left child, we still need "()"
            if (root->left == NULL) {
                ans += "()";
            }

            ans += "(";
            traverse(root->right, ans);
            ans += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";

        traverse(root, ans);

        return ans;
    }
};