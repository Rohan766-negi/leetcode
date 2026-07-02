class Solution {
private:
    bool bsthai(TreeNode* root, long long mini, long long maxi) {

        if(root == NULL)
            return true;

        if(root->val <= mini || root->val >= maxi)
            return false;

        return bsthai(root->left, mini, root->val) &&
               bsthai(root->right, root->val, maxi);
    }

public:
    bool isValidBST(TreeNode* root) {

        return bsthai(root, LLONG_MIN, LLONG_MAX);
    }
};