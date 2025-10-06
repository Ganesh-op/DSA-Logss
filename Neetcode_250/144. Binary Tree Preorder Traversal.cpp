class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);     // Root
        helper(root->left, ans);      // Left
        helper(root->right, ans);     // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};