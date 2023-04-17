class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }

        vector<int> ans;
        for(auto i: m) {
            while(i.second) {
                ans.push_back(i.first);
                i.second--;
            }
        }

        return ans;
    }
};
