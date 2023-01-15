class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, j = INT_MAX;
        for(auto num: nums) {
            if(num <= i) i = num;
            else if(num <= j) j = num;
            else return true;
        }
        return false;
    }
};
