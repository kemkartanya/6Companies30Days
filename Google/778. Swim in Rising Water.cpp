class Solution {
public:
    typedef pair<int, pair<int, int>> dt;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));
        priority_queue<dt, vector<dt>, greater<dt>> pq; 

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int t = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            if(x == n - 1 && y == n - 1)
            return t;

            int dx[] = {0, 0, -1, 1};
            int dy[] = {-1, 1, 0, 0};

            for(int k=0; k<4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny] != 1) {
                    vis[nx][ny] = 1;
                    pq.push({max(t, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};
