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
void solve(TreeNode* root,int val){
    if(root->val>val){
        if(root->left==NULL){
           TreeNode*  newNode = new TreeNode(val);
            root->left=newNode;
            return;
        }
        else{
          solve( root->left, val);
        }
    }
    else{
        if(root->right==NULL){
          TreeNode*  newNode = new TreeNode(val);
            root->right=newNode;
             return;
        }
        else{
            solve(root->right, val);
        }
    }
}
       
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          if(root==NULL){
            root= new TreeNode(val);
            return root;
        }
        TreeNode* nroot=root;
        solve(nroot,val);
        return root;
    }
};