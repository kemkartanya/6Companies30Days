class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> fruitFreq;
        int res = 0;
        int n = fruits.size();

        for (int l = 0, r = 0; r < n; r++) {
            int fruit = fruits[r];
            fruitFreq[fruit]++;

            while (fruitFreq.size() > 2) {
                int leftFruit = fruits[l];
                fruitFreq[leftFruit]--;
                if (fruitFreq[leftFruit] == 0) {
                    fruitFreq.erase(leftFruit);
                }
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
