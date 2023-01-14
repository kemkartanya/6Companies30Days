class Solution {
public:
    vector<int> best;
    int bobpoints;
    void solve(int numArrows, vector<int>& aliceArrows, vector<int>& bobArrows, int i, int points) {
        if(i == 0) {
            if(points > bobpoints) {
                bobpoints = points;
                bobArrows[i] = numArrows;
                best = bobArrows;
            }
            return;
        }
        solve(numArrows, aliceArrows, bobArrows, i - 1, points);
        if(numArrows > aliceArrows[i]) {
            bobArrows[i] = aliceArrows[i] + 1;
            solve(numArrows - bobArrows[i], aliceArrows, bobArrows, i - 1, points + i);
            bobArrows[i] = 0;
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        best = vector<int> (12, 0);
        vector<int> bobArrows(12, 0);
        bobpoints = 0;
        solve(numArrows, aliceArrows, bobArrows, 11, 0);
        return best;   
    }
};

// used backtracking, tc: O(2^n), sc: O(n)
