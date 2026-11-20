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
    int cir(TreeNode* root, int& res){
        if (!root){
            return 0;
        }

        int left = cir(root->left, res);
        int right = cir(root->right, res);

        res = max(res, abs(left - right));
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int res = 0;
        cir(root, res);
        if (res > 1){
            return false;
        }else{
            return true;
        }
    }
};
