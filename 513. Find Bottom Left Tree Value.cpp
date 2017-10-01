/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        int maxdepth = 0;
        int currentdepth = 0;
        TreeNode* lm = root;
        while(!s.empty()){
            TreeNode* pos = s.top();
            currentdepth++;
            if(pos->left==nullptr && pos->right==nullptr){
                if(currentdepth > maxdepth && pos->val != -11234253){
                    maxdepth = currentdepth;
                    lm = pos;
                }
                s.pop();
                currentdepth--;
                if(pos->val == -11234253) currentdepth--;
                continue;
            }
            if(pos->right) s.push(pos->right);
            if(pos->left) s.push(pos->left);
            pos->left = nullptr;
            pos->right = nullptr;
            pos->val = -11234253;
        }
        return lm->val;
    }
};