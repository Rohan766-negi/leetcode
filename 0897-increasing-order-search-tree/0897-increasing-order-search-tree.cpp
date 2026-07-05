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
    void inoder(TreeNode* root,vector<int>&ino){
      if(root==NULL){
          return;
      }
          inoder(root->left,ino);
          ino.push_back(root->val);
          inoder(root->right,ino);
          

  }
public:
    TreeNode* increasingBST(TreeNode* root) {
        

         vector<int>ino;
	inoder(root,ino);


    TreeNode* newnode= new TreeNode(ino[0]);
    TreeNode* current=newnode;

    for(int i=1; i<ino.size(); i++){
        TreeNode* temp= new TreeNode (ino[i]);

        current->left=NULL;
        current->right=temp;
        current=temp;
    }
    current->left=NULL;
    current->right=NULL;
    return  newnode;
    }
};