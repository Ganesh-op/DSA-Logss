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
    void helper(TreeNode* root, set<int>&s){
        if(!root) return;
        helper(root->left,s);
        s.insert(root->val);
        helper(root->right,s);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int>values;
        helper(root,values);
        vector<int>vec(values.begin(),values.end());
        if(k<0 && vec.size()<k){
            return -1;
        }
        else{
            return vec[k-1];
        }
    }
};