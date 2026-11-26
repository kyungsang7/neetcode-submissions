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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()){
            ans.push_back(dq.front()->val);
            int count = dq.size();
            for(int i = 0; i < count; i++){
                TreeNode* head = dq.front();
                if(head->right){
                    dq.push_back(head->right);
                }
                if(head->left){
                    dq.push_back(head->left);
                }
                dq.pop_front();
            }
        }
        return ans;
    }
};
