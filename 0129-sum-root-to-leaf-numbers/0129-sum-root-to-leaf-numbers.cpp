/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int psum, int& ans) {
        if (root == NULL)
            return;
        psum = psum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            ans = ans + psum;
            return;
        }

        int x = psum;

        solve(root->left, x, ans);
        solve(root->right, x, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int psum = 0;
        solve(root, psum, ans);
        return ans;
    }
};