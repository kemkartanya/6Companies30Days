class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long int res = 0;

        vector<long long int> prefix(nums.size() + 1, 0);
        for(int i=0; i<nums.size(); i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        stack<pair<int, int>> st;
        for(int i=0; i<nums.size(); i++) {
            int newStart = i;
            while(!st.empty() && st.top().second > nums[i]) {
                pair<int, int> temp = st.top(); st.pop();
                long long int total = prefix[i] - prefix[temp.first];
                res = max(res, temp.second * total);
                newStart = temp.first;
            }
            st.push({newStart, nums[i]});
        }

        while(!st.empty()) {
            pair<int, int> temp = st.top(); st.pop();
            long long int total = prefix[nums.size()] - prefix[temp.first];
            res = max(res, total * temp.second);
        }

        return res % 1000000007;
    }
};
