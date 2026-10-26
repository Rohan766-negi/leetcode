class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < times.size(); i++) {
            int x = times[i][0];
            int y = times[i][1];
            int w = times[i][2];
            adj[x].push_back({y, w});
        }
        vector<int> dis(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dis[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nei : adj[node]) {
                int nodenew = nei.first;
                int d = nei.second;

                if (dis[nodenew] > d + w) {
                    dis[nodenew] = d + w;
                    pq.push({dis[nodenew], nodenew});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};