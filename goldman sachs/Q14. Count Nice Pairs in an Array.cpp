class Solution {
public:
    int rev(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            v[i] = nums[i] - rev(nums[i]);
        }

        unordered_map<int, long int> mp;
        for(int i=0; i<n; i++) mp[v[i]]++;

        long int ans = 0, mod = 1e9 + 7;
        for(auto x: mp) {
            ans = (ans + (x.second * (x.second - 1)) / 2) % mod;
        }
        return ans;
    }
};
