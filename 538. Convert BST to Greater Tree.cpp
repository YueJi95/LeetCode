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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        int value = 0;
        pushnode(root, s);
        while(s.empty() == false){
            TreeNode* tem = s.top();
            s.pop();
            int t = tem->val;
            tem->val = tem->val + value;
            value = value + t;
        }
        return root;
    }
    
    void pushnode(TreeNode* t, stack<TreeNode*>& s){
        if(t == nullptr) return;
        if(t->left != nullptr) pushnode(t->left, s);
        s.push(t);
        if(t->right != nullptr) pushnode(t->right, s);
    }
};