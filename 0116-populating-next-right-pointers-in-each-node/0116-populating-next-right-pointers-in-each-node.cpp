/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
void solve(Node*tem){
    if(tem==NULL){
        return;
    }
    if(tem->next&&tem->next->left){
        tem->right->next=tem->next->left;
    }
    if( tem->left){
     tem->left->next=tem->right;
    }
    solve(tem->left);
    solve(tem->right);

}
    Node* connect(Node* root) {
        Node* tem=root;
        solve(tem);
        return root;
    }
};