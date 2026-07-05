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
    void inoder(TreeNode* root, vector<int>& ino) {
        if (root == NULL) {
            return;
        }
        inoder(root->left, ino);
        ino.push_back(root->val);
        inoder(root->right, ino);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ino;
        inoder(root, ino);

        int i = 0;
        int j = ino.size() - 1;
        while (i < j) {
            int sum = ino[i] + ino[j];
            if (sum == k) {
                return true;
            }
            if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};