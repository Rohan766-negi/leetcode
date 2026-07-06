/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ino;

        while(head!=NULL){
            ino.push_back(head->val);
            head=head->next;
        }



        return mkbst(0,ino.size()-1,ino);

        
    }
};