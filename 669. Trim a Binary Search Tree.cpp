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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        while(root != NULL){
            if(root->val > R) root = root->left;
            else if(root->val < L) root = root->right;
            else break;
        }
        if(root != NULL) root->left =  trimBST(root->left, L, R);
        if(root != NULL) root->right =  trimBST(root->right, L, R);
        return root;
    }
};