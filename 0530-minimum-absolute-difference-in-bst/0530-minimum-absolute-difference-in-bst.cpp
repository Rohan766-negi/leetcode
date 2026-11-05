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
void inorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    int getMinimumDifference(TreeNode* root) {
         vector<int> arr;
        inorder(root, arr);

        vector<int> diff;

        for(int i = 1; i < arr.size(); i++) {
            diff.push_back(arr[i] - arr[i-1]);
        }

        return *min_element(diff.begin(), diff.end());
    }

    
};