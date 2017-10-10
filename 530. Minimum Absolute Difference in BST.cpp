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
    int getMinimumDifference(TreeNode* root) {
        int min = 100000000;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != nullptr){
                q.push(temp->left);
                int m = abs(temp->val - rc(temp->left)->val);
                if(m < min) min = m;
            } 
            if(temp->right != nullptr){
                int m = abs(temp->val - lc(temp->right)->val);
                if(m < min) min = m;
                q.push(temp->right);
            }
        }
        return min;
    }
    
    TreeNode* rc(TreeNode* root){
        if(root == nullptr) return nullptr;
        while(root->right != nullptr){
            root = root->right;
        }
        return root;
    }
    TreeNode* lc(TreeNode* root){
        if(root == nullptr) return nullptr;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
};