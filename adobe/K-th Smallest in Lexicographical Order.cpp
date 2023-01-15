class Solution {
public:
    int countNodes(long n, long cur) {
        long total = 0;

        long next = cur + 1;
        while(cur <= n) {
            total += min(n - cur + 1, next - cur);
            cur *= 10;
            next *= 10;
        }

        return (int) total;
    }
    int findKthNumber(int n, int k) {
        long cur = 1;
        k -= 1;

        while(k > 0) {
            int nodes = countNodes(n, cur);
            if(k >= nodes) {
                cur += 1;
                k -= nodes;
            } else {
                cur *= 10;
                k--;
            }
        }

        return cur;
    }
};
