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

    bool cir(TreeNode* root, int left_val, int right_val){
        if(!root){
            return true;
        }
        if(root->val >= left_val || root->val <= right_val){
            return false;
        }
        
        bool res = true;
        if(root->left && root->left->val >= root->val){
            res = false;
        }
        if(root->right && root->right->val <= root->val){
            res = false;
        }
        return res && cir(root->left, min(left_val, root->val), right_val) && cir(root->right, left_val, max(right_val, root->val));
    }


    bool isValidBST(TreeNode* root) {
        return cir(root, INT_MAX, -INT_MAX);
    }
};
