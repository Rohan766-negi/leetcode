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
    void inoder(TreeNode* root, vector<int>& ino) {
        if (root == NULL) {
            return;
        }
        inoder(root->left, ino);
        ino.push_back(root->val);
        inoder(root->right, ino);
    }
    TreeNode* mkbst(int s, int e, vector<int> ino) {
        if (s > e) {
            return NULL;
        }
        int mid = (s + e) / 2;

        TreeNode* root = new TreeNode(ino[mid]);
        root->left = mkbst(s, mid - 1, ino);
        root->right = mkbst(mid + 1, e, ino);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ino;
        inoder(root, ino);
        return mkbst(0, ino.size() - 1, ino);
    }
};