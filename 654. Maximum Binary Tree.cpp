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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        int max = nums[0];
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        vector<int> l;
        vector<int> r;
        for(int i = 0; i < index; i++){
            l.push_back(nums[i]);
        }
        for(int i = index + 1; i < nums.size(); i++){
            r.push_back(nums[i]);
        }
        TreeNode* root = new TreeNode(max);
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);
        return root;
    }
};