class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        // Recursively invert
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        // Swap children
        swap(root->left,root->right);
        return root;
    }
};