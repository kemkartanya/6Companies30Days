class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        int sum = 0, curr_f = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            curr_f += nums[i] * i;
        }
        ans = max(ans, curr_f);
        for(int i=n-1; i>0; i--) {
            curr_f += sum;
            curr_f -= n * nums[i];
            ans = max(ans, curr_f);
        }
        return ans;
    }
};
