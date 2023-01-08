#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    ll MOD = 1e9 + 7;
    ll dijkstra(vector<vector<pll>> &g, int n, int src) {
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<ll> ways(n);
        vector<ll> dist(n, LONG_MAX);
        
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto[d, u] = pq.top(); pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, time] : g[u]) {
                if(dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if(dist[v] == d + time) {
                    ways[v] = (ways[u] + ways[v]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> g(n);
        for(ll i=0; i<roads.size(); i++) {
            ll u = roads[i][0], v = roads[i][1], t = roads[i][2];
            g[u].push_back({v, t});
            g[v].push_back({u, t});
        }
        return dijkstra(g, n, 0);
    }
};
