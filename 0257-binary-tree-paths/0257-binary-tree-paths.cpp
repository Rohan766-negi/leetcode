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
private:
    void solve(TreeNode* root, vector<string>& ans, string out) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(out + to_string(root->val));
            return;
        }
        string c =  to_string(root->val)+"->";
        solve(root->left, ans, out + c);
        solve(root->right, ans, out + c);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string out = "";
        solve(root, ans, out);
        return ans;
    }
};