class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
              
        
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

       
        map<int, bool> visit;

        queue<int> q;
        int i = source;

        q.push(i);
        visit[i] = 1;
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
           if(fr==destination){
            return true;
           }
            for (auto j : adj[fr]) {
                if (!visit[j]) {
                    q.push(j);
                    visit[j] = 1;
                }
            }
        }

        return false;
    }
};