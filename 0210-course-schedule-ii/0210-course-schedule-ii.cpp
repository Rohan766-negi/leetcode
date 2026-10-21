
class Solution {
public:
    bool topo(int node, unordered_map<int, list<int>>& adj,
              vector<int>& vis, vector<int>& dfsVis, stack<int>& s) {

        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                if (topo(nei, adj, vis, dfsVis, s))
                    return true;
            }
            else if (dfsVis[nei]) {
                return true;  
            }
        }

        dfsVis[node] = 0;
        s.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adj[y].push_back(x);   
        }

        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (topo(i, adj, vis, dfsVis, s))
                    return {};
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
