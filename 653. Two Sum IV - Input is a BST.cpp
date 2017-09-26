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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            TreeNode* pos = q.front();
            q.pop();
            TreeNode* t = find(root, k - pos->val);
            if(t != nullptr && t != pos) return true;
            if(pos->left != nullptr) q.push(pos->left);
            if(pos->right != nullptr) q.push(pos->right);
        }
        return false;
    }
    
    TreeNode* find(TreeNode* root, int k) {
        if(root == nullptr) return nullptr;
        TreeNode* pos = root;
        while(pos != nullptr){
            if(pos->val < k) pos = pos->right;
            else if(pos->val > k) pos = pos->left;
            else return pos;
        }
        return nullptr;
    }
};