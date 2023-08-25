class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;
        for(int i=0; i<m-2; i++) {
            for(int j=0; j<n-2; j++) {
                int sum = 0;
                
                for(int z=j; z<j+3; z++) {
                    sum += grid[i][z];
                }
                
                sum += grid[i+1][j+1];
                
                for(int z=j; z<j+3; z++) {
                    sum += grid[i+2][z];
                }
                
                ans = max(sum, ans);
            }
        }

        return ans;
    }
};
