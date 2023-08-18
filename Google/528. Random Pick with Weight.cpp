class Solution {
public:
    vector<int> w;
    Solution(vector<int>& w) {
        for(int i=1; i<w.size(); i++) {
            w[i] += w[i-1];
        }
        this->w = w;
    }
    
    int pickIndex() {
        int index = rand() % w.back();

        return upper_bound(w.begin(), w.end(), index) - w.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
