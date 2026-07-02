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
    TreeNode* mino(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (root->val > key) {
            root->left=deleteNode(root->left, key);
        }
        if (root->val < key) {
          root->right=  deleteNode(root->right, key);
        }
        if (root->val == key) {

            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->left != NULL && root->right != NULL) {
                int temp = mino(root->right)->val;
                root->val = temp;
                root->right = deleteNode(root->right, temp);
                return root;
            }
        }

        return root;
    }
};