/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* mapNode(TreeNode* root, TreeNode* target,
                      map<TreeNode*, TreeNode*>& mp) {
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == target) {
                res = front;
            }
            if (front->left) {
                mp[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                mp[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    void solve(TreeNode* targetNode, map<TreeNode*, TreeNode*> mp,
               vector<int>& ans, int k) {
        map<TreeNode*, bool> vi;
        queue<TreeNode*> q;
        q.push(targetNode);
        vi[targetNode] = true;
        int dis = 0;

        while (!q.empty()) {
            if (dis == k) {
                break;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left && !vi[front->left]) {

                    q.push(front->left);
                    vi[front->left] = true;
                }
                if (front->right && !vi[front->right]) {

                    q.push(front->right);
                    vi[front->right] = true;
                }

                if (mp[front] && !vi[mp[front]]) {

                    q.push(mp[front]);
                    vi[mp[front]] = true;
                }
            }
            dis++;
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        vector<int> ans;
        TreeNode* targetNode = mapNode(root, target, mp);
        solve(targetNode, mp, ans, k);

        return ans;
    }
};