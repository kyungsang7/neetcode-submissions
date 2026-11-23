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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_res;
        vector<TreeNode*> q_res;

        cir(root, p, p_res);
        cir(root, q, q_res);

        TreeNode* ans = nullptr;

        for(int i = 0; i < min(p_res.size(), q_res.size()); i++){
            if(p_res[i] == q_res[i]){
                ans = p_res[i];
            }
        }
        return ans;
    }

private:
    bool cir(TreeNode* root, TreeNode* tar, vector<TreeNode*>& res){
        if(!root){
            return false;
        }
        
        res.push_back(root);

        if(root == tar){
            return true;
        }

        bool l = cir(root->left, tar, res);
        bool r = cir(root->right, tar, res);

        if (l || r){
            return true;
        }else{
            res.pop_back();
            return false;
        }
        
    }
};
