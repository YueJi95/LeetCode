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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        long sum = 0;
        int count = 1;
        int bcount = 0;
        int scount = 0;
        vector<double> result;
        if(root == NULL) return result;
        q.push(root);
        while(q.empty() == false){
            TreeNode* tem = q.front();
            count--;
            if(tem->left != NULL){
                q.push(tem->left);
                scount++;
            }
            if(tem->right != NULL){
                q.push(tem->right);
                scount++;
            }
            sum = sum + tem->val;
            bcount++;
            if(count == 0){
                result.push_back(sum / (double)bcount);
                count = scount;
                scount = 0;
                bcount = 0;
                sum = 0;
            }
            q.pop();
        }
        return result;
    }
};