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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) sum = sum + root->left->val;
        sum = sum + sumOfLeftLeaves(root->left);
        sum = sum + sumOfLeftLeaves(root->right);
        return sum;
    }
};