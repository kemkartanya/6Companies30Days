class Solution {
public:
    unordered_map<string, double> mp;
    bool isValid(int row, int column, int n) {
        return row >= 0 && row < n && column >= 0 && column < n;
    }
    double solve(int n, int k, int row, int column, int dx[], int dy[]) {
        if(!isValid(row, column, n)) return 0;
        if(k == 0) return 1;

        string s = to_string(k) + "_" + to_string(row) + "_" + to_string(column);
        if(mp.find(s) != mp.end()) return mp[s];

        double ans = 0;
        for(int i=0; i<8; i++) {
            ans += solve(n, k - 1, row + dx[i], column + dy[i], dx, dy) * 1 / 8;
        }
        return mp[s] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

        return solve(n, k, row, column, dx, dy);
    }
};
