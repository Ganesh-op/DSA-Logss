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

    //brute force approach
    //time complexity: O(n)
    //space complexity: O(h): due to recursive stack(height of tree)

    //recursive function to delete target leaf nodes
    TreeNode* solve(TreeNode* root, int target)
    {
        //base case: checking if root is NULL
        if(root==NULL)
            return NULL;

        //recursively processing 'left' subtree
        (root->left)=solve(root->left,target);
        //recursively processing 'right' subtree
        (root->right)=solve(root->right,target);

        //checking if current node is a 'leaf node'
        if((root->left == NULL) && (root->right == NULL))
        {
            //it current leaf-node's value equals 'target, setting it NULL(deleting it)
            if(root->val == target)
                return NULL;
        }
        //otherwise, returning the current node
        return root;
    }

    //given function
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        //function call to delete leaf nodes with 'target' value
        root=solve(root,target);
        //returning the updated tree
        return root;
    }
};