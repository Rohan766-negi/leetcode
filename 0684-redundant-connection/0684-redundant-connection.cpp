
class Solution {
public:
    bool iscycle(vector<vector<int>>& adj, int src, int dest) {
        vector<bool> visit(adj.size(), false);
        queue<int> q;

        q.push(src);
        visit[src] = 1;

        while (!q.empty()) {
            int fr = q.front();
            q.pop();

            if (fr == dest) {
                return 1;
            }

            for (auto j : adj[fr]) {
                if (!visit[j]) {
                    visit[j] = 1;
                    q.push(j);
                }
            }
        }

        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++) {
            int x = edges[i][0];
            int y = edges[i][1];

            bool ans = iscycle(adj, x, y);

            if (ans == 1) {
                return edges[i];
            }

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        return {};
    }
};
