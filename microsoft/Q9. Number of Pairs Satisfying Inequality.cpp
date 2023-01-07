class Solution {
public:
    long long ans;
    void countpairs(vector<int> &c, int s, int m, int e, int d) {
        int l = s, r = m + 1;
        while(l <= m && r <= e) {
            if(c[l] <= c[r] + d) ans += (e - r + 1), l++;
            else r++;
        }
        sort(c.begin() + s, c.begin() + e + 1);
    }
    void mergeSort(vector<int> &c, int s, int e, int d) {
        if(s == e) return;
        int m = s + (e - s) / 2;
        mergeSort(c, s, m, d);
        mergeSort(c, m + 1, e, d);

        countpairs(c, s, m, e, d);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ans = 0;
        int n = nums1.size();
        vector<int> c(n, 0);
        for(int i=0; i<n; i++) {
            c[i] = nums1[i] - nums2[i];
        }

        mergeSort(c, 0, n-1, diff);
        return ans;
    }
};
