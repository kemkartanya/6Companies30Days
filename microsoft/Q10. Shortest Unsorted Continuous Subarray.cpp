class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX, mx=INT_MIN;
        int n=nums.size();
        
        //Finding first and the last position
        for(int i=1;i<n;i++){ // decreasing value
            if(nums[i]<nums[i-1]){
                mn = min(mn, nums[i]); 
            }
        }
        for(int i=n-2;i>=0;i--){ // increasing value
            if(nums[i]>nums[i+1]){
                mx = max(mx, nums[i]); 
            }
        }
        if(mn == INT_MAX && mx == INT_MIN) return 0; // finding if array is already sorted: if sorted then return 0

        //If array is not sorted
        int start=0, end=n-1;
        for(;start<n;start++){ // finding start point
            if(nums[start] > mn) break; // find index in the left for a no. greater than the min found
        }
        for(;end>=0;end--){ // finding end point
            if(nums[end] < mx) break; // find index in the right for a no. lesser than the max found
        }
        return end-start+1; // ans: unsorted array
    }
};
