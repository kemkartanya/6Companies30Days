class Solution {
public:
    long long dp[4001][1001];
    long long int solve(int start, int end, int k) {
        if(dp[start+1000][k] != -1) return dp[start+1000][k] % 1000000007;
        
        if(start > end && k == 0 || start < end && k == 0) return 0;
        if(start == end && k == 0) return 1;
        
        return dp[start+1000][k] = (solve(start + 1, end, k - 1) + solve(start - 1, end, k - 1)) % 1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k) % 1000000007;
    }
};
