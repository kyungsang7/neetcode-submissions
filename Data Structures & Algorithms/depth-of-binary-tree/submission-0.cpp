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
    int cir(TreeNode* root, int depth){
        if(!root){
            return depth;
        }
        int a = cir(root->left, depth + 1);
        int b = cir(root->right, depth + 1);
        return max(a, b);
    }

    int maxDepth(TreeNode* root) {
        return cir(root, 0);
    }
};
