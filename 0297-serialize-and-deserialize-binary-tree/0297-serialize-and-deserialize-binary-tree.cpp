
class Codec {
public:
    void traversal(TreeNode* root, string &ans) {
        if(root == NULL) {
            ans += "null,";
            return;
        }

        ans += to_string(root->val) + ",";

        traversal(root->left, ans);
        traversal(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans = "";
        traversal(root, ans);
        return ans;
    }

    TreeNode* solve(string &data, int &i) {

        int j = data.find(',', i);
        string s = data.substr(i, j-i);
        i = j + 1;

        if(s == "null") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(s));

        root->left = solve(data, i);
        root->right = solve(data, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};
