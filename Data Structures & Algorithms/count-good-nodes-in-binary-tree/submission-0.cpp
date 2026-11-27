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
    int rec(TreeNode* root, int max_value){
        if(!root){
            return 0;
        }

        if(root->val >= max_value){
            return 1 + rec(root->left, root->val) + rec(root->right, root->val);
        }else{
            return rec(root->left, max_value) + rec(root->right, max_value);
        }
    }

    int goodNodes(TreeNode* root) {
        return rec(root, -101);
    }
};
