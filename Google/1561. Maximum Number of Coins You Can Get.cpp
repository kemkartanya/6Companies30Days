class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int j = piles.size() - 1;
        int ans = 0;
        for(int i=0; i<piles.size() / 3; i++) {
            j--;
            ans += piles[j];
            j--;
        }
        return ans;
    }
};
