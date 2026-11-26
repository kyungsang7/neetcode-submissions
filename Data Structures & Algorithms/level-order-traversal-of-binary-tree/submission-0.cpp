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
private:
    void cir(TreeNode* root, vector<vector<int>> &ans, int depth){
        if (!root){
            return;
        }

        if(ans.size() <= depth){
            ans.push_back({});
        }

        cir(root->left, ans, depth + 1);
        cir(root->right, ans, depth + 1);
        ans[depth].push_back(root->val);

    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        cir(root, ans, 0);
        return ans;
    }
};
