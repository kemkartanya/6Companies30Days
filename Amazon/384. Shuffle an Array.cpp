class Solution {
public:
    vector<int> array;
    Solution(vector<int>& nums) {
        array = nums;
    }
    
    vector<int> reset() {
        return array;
    }
    
    vector<int> shuffle() {
        vector<int> random = array;
        random_shuffle(random.begin(), random.end());
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
