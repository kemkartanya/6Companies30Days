//uses ordered set and gnu c++ pbds
//more info about data structure here: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        vector<int> pos2(n);
        for(int i=0; i<n; i++) pos2[nums2[i]] = i;

        vector<int> pre(n), suf(n);
        ordered_set s, s2;
        for(int i=0; i<n; i++) {
            pre[i] = s.order_of_key(pos2[nums1[i]]);
            s.insert(pos2[nums1[i]]);
        }
        for(int i=n-1; i>=0; i--) {
            suf[i] = s.order_of_key(-pos2[nums1[i]]);
            s.insert(-pos2[nums1[i]]);
        }

        for(int i=1; i<n-1; i++) {
            ans += pre[i]*1LL*suf[i];
        }
        return ans;
    }
};
