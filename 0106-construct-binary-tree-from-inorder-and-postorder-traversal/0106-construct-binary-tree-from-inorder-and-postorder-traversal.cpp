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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& pindex,
                    int st, int end, int n, map<int, int>& mp) {
        if (pindex < 0 || st > end) {
            return NULL;
        }
        int element = postorder[pindex--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
         root->right =
            solve(postorder, inorder, pindex, position + 1, end, n, mp);
        root->left = solve(postorder, inorder, pindex, st, position - 1, n, mp);
       
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pindex = postorder.size() - 1;
        int n = inorder.size();
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* ans = solve(postorder, inorder, pindex, 0, n - 1, n, mp);
        return ans;
    }
};