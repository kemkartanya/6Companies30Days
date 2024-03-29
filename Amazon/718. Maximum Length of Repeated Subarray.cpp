lass Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        int res = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        // vector<int> res;
        // for(int i = 0; i < m+1; i++){
        //     for(int j = 0; j < n+1; j++){
        //         res.push_back(dp[i][j]);
        //     }
        // }
        // return *max_element(res.begin(), res.end()); 
        return res;       
    }
};
