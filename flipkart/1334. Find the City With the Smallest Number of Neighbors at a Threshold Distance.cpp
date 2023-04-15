class Solution {
public:
    int dijkstra(int n, int src, vector<pair<int, int>> adj[], int disTh) {
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= disTh)
                cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        int city = -1, cntCity = INT_MAX;
        for(int i=0; i<n; i++) {
            int cnt = dijkstra(n, i, adj, distanceThreshold);
            if(cnt <= cntCity) {
                cntCity = cnt;
                city = i;
            }
        }
        return city;
    }
};
