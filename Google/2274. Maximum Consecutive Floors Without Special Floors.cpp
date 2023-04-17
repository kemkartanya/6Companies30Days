class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        int start = bottom;
        for(int i=0; i<special.size(); i++) {
            if(start <= special[i]) {
                ans = max(ans, special[i] - start);
                start = special[i] + 1;
            }
        }
        if(start <= top) ans = max(ans, top - start + 1);
        return ans;
    }
};
