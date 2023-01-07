class Solution {
public:
    bool bdfs(int nd, int tsp, int par, vector<int> adj[], vector<int> &tsb) {
        tsb[nd] = tsp;
        if(nd == 0) return 1;
        for(auto v: adj[nd]) {
            if(v != par && bdfs(v, tsp+1, nd, adj, tsb))
            return 1;
        }
        tsb[nd] = -1;
        return 0;
    }
    int adfs(int nd, int ts, int par, vector<int> adj[], vector<int> &tsb, vector<int> &amount) {
        int ans = INT_MIN;
        for(auto v: adj[nd]) {
            if(v != par) ans = max(ans, adfs(v, ts+1, nd, adj, tsb, amount));
        }
        if(ans == INT_MIN) ans = 0;

        if(tsb[nd] == -1 || tsb[nd] > ts) ans += amount[nd];
        if(tsb[nd] == ts) ans += amount[nd] / 2;

        return ans;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> adj[n], tsb(n, -1);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bdfs(bob, 0, -1, adj, tsb);

        return adfs(0, 0, -1, adj, tsb, amount);
    }
};
