class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> answer(m, vector<int> (n, 0));
        vector<vector<int>> summ(m + 1, vector<int> (n + 1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                summ[i][j] = summ[i-1][j] - summ[i-1][j-1] + summ[i][j-1] + mat[i-1][j-1];
            }
        }



        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                int x1 = max(0, i-k);
                int y1 = max(0, j-k);
                int x2 = min(m, i+k+1);
                int y2 = min(n, j+k+1);

                answer[i][j] = summ[x2][y2] - summ[x1][y2] - summ[x2][y1] + summ[x1][y1];
            }
        }

        return answer;
    }
};
