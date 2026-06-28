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
  TreeNode* solve(TreeNode* root,int start,
  map<TreeNode* ,TreeNode* >&mp){
   TreeNode* res=NULL;
   queue<TreeNode*>q;
   q.push(root);
   mp[root]=NULL;
   while (!q.empty()) {
			TreeNode* first = q.front();
			q.pop();
			if (first->val == start) {
				res = first;
			}
			if (first->left) {
				mp[first->left] = first;
				q.push(first->left);
			}
			if (first->right) {
				mp[first->right] = first;
				q.push(first->right);
			}
		}
		return res;
		
	}

  

  int  burn(TreeNode* root,map<TreeNode* ,TreeNode* >mp){
	map<TreeNode*, bool>vi;
		queue<TreeNode*>q;
		q.push(root);
		vi[root] = true;
		int ans=0;
		
		while (!q.empty()) {
		    bool flag = 0;
			int size = q.size();
			for (int i = 0; i<size; i++) {
				TreeNode* front = q.front();
				q.pop();
				if (front->left && !vi[front->left]) {
					flag = 1;
					q.push(front->left);
					vi[front->left] = true;
				}
				if (front->right && !vi[front->right]) {
					flag = 1;
					q.push(front->right);
					vi[front->right] = true;
				}
				
				if (mp[front] && !vi[mp[front]]) {
					flag = 1;
					q.push(mp[front]);
					vi[mp[front]] = true;
				}
				
			}
			if (flag == 1) {
				ans++;
			}
			
		}
		return ans;
  }
public:
    int amountOfTime(TreeNode* root, int start) {
     map<TreeNode* ,TreeNode* >mp;
     TreeNode* target=solve(root,start,mp);
     int ans=burn(target,mp);
     return ans;

    }
};