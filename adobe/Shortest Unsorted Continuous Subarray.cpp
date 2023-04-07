class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int end = -1, mx = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] < mx) {
                end = i;
            } else {
                mx = nums[i];
            }
        }

        int start = 0, mn = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i] > mn) {
                start = i;
            } else {
                mn = nums[i];
            }
        }

        return end - start + 1;
    }
};
