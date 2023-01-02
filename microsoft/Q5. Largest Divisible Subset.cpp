class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), max_v = 1;
        int dp[n];
        for(int i=0; i<n; i++) dp[i] = 1;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j] + 1), max_v = max(max_v, dp[i]);
            }
        }

        int prev = -1;
        vector<int> ans;
        for(int i=n-1; i>=0; i--) {
            if(dp[i] == max_v && (prev % nums[i] == 0 || prev == -1)) {
                ans.push_back(nums[i]);
                prev = nums[i];
                max_v--;
            }
        }
        return ans;
    }
};
