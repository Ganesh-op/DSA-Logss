class Solution {
public:
    int count = 0;
    int maxVal = INT_MIN;

    void helper(TreeNode* node) {
        if (node == nullptr) return;

        int oldMax = maxVal;
        maxVal = max(maxVal, node->val);

        if (node->val == maxVal) {
            count++;
        }

        helper(node->left);
        helper(node->right);

        // Backtrack maxVal
        maxVal = oldMax;
    }

    int goodNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};