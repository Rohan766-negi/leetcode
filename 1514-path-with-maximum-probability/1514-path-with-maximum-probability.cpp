class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        map<int, list<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            double w = succProb[i];
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        vector<double> dis(n + 1, 0);

        priority_queue<pair<double,int>>pq;

        dis[start_node] = 1;
        pq.push({1, start_node});
        while (!pq.empty()) {
            double w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nei : adj[node]) {
                int nodenew = nei.first;
                double d = nei.second;

                if (dis[nodenew] < d * w) {
                    dis[nodenew] = d * w;
                    pq.push({dis[nodenew], nodenew});
                }
            }
        }

        return dis[end_node];
    }
};