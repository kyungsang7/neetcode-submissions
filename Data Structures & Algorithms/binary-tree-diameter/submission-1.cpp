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
    int cir(TreeNode* root, int& ans){
        if (!root){
            return 0;
        }
        
        int left = cir(root->left, ans);
        int right = cir(root->right, ans);

        ans = max(ans, left + right + 1);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        cir(root, ans);
        return ans - 1;
    }
};
