class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            vector<int> v;
            for(int j=i; j<n; j++) {
                if(nums[j] % p == 0) cnt++;
                v.push_back(nums[j]);

                if(cnt <= k) 
                ans.insert(v);
            }
        }
        return ans.size();
    }
};
