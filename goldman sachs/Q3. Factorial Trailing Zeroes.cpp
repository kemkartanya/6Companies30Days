class Solution {
public:
    int trailingZeroes(int n) {
        int n5 = 0, n2 = 0;

        for(int i=5; i<=n; i*=5) {
            n5 += n / i;
        }
        for(int i=2; i<=n; i*=2) {
            n2 += n / i;
        }

        return min(n5, n2);
    }
};
