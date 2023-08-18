class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];

        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({w, v});
        }

        int dist[n+1];
        for(int i=1; i<=n; i++) dist[i] = INT_MAX;			
        priority_queue<p, vector<p>, greater<p>> pq; //minHeap	
        vector<int> vis(n+1, 0);		
                    
        dist[k] = 0;			
        pq.push({0, k});
        vis[k] = 1;
                    
        while(!pq.empty()) {			
            pair<int, int> u = pq.top();			
            pq.pop();

            for(auto v: adj[u.second]) {
                if(dist[v.second] > dist[u.second] + v.first) {
                    vis[v.second] = 1;
                    dist[v.second] = min(dist[v.second], dist[u.second] + v.first);
                    pq.push({dist[v.second], v.second});
                }
            }
        }	
        
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(vis[i] == 0) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
