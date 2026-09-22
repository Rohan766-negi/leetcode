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
    void find(TreeNode* root, int &mini, int vall) {
        if(root == NULL){
            return;
        }

        if(root->val > vall){
            if(mini == -1 || root->val < mini){
                mini = root->val;
            }
        }

        find(root->left, mini, vall);
        find(root->right, mini, vall);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        int mini = -1;

        find(root, mini, root->val);

        return mini;
    }
};