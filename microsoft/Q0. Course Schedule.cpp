class Solution {
public:
    bool detectCycle(vector<int> adj[], vector<int>& vis, vector<int>& rvis, int u) {
        if(vis[u] == false) {
            vis[u] = true; rvis[u] = true;
            for(auto v: adj[u]) {
                if(!vis[v] && detectCycle(adj, vis, rvis, v)) return true;
                else if(rvis[v]) return true;
            }
        }
        rvis[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> rvis(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i] && detectCycle(adj, vis, rvis, i)) return false;
        }
        return true;
    }
};
