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
    void solve(int &ans,int low,int high,TreeNode* &root){
        if(root==NULL){
            return ;
        }
        if(root->val<=high&&root->val>=low){
            ans+=root->val;
        }
        solve(ans,low,high,root->left);
        solve(ans,low,high,root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        solve(ans,low,high,root);
        return ans;
    }
};