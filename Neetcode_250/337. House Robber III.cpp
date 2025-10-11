class Solution {
public:

    int fun(TreeNode* root, bool par_robbed, unordered_map<TreeNode*, vector<int>> &dp){
        if(!root)   return 0;
        if (!dp.count(root)) dp[root] = vector<int>(2, -1);
        if(dp[root][par_robbed]!=-1)    return dp[root][par_robbed];

        int rob = fun(root->left, 1, dp) + fun(root->right, 1, dp) + root->val;
        int no_rob = fun(root->left, 0, dp) + fun(root->right, 0, dp);

        if(par_robbed==1)   return dp[root][par_robbed] = no_rob;
        else return dp[root][par_robbed] = max(rob, no_rob);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        dp[root] = {-1, -1};
        return fun(root, 0, dp);
    }
};