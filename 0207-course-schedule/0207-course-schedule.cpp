class Solution {
public:
    bool checkcycle(int node, unordered_map<int, bool>& vis,
                    unordered_map<int, bool>& dfsvis,
                    unordered_map<int, list<int>>& adj) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                bool isit = checkcycle(nei, vis, dfsvis, adj);
                if (isit) {
                    return true;
                }
            } else if (dfsvis[nei]) {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adj[x].push_back(y);
        }
        unordered_map<int, bool> vis;

        unordered_map<int, bool> dfsvis;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                bool isit = checkcycle(i, vis, dfsvis, adj);
                if (isit) {
                    return false;
                }
            }
        }
        return true;
    }
};