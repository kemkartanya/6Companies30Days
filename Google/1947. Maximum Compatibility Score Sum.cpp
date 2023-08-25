class Solution {
public:
    int n, m;
    int compatibility(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int j) {
        int res = 0;
        for(int k = 0; k < n; k++) {
            res += !(mentors[j][k] ^ students[i][k]);
        }
        return res;
    }
    int solve(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& matched, int i) {
        if(i >= m) return 0;

        int ans = 0;
        for(int j=0; j<m; j++) {
            if(matched[j] == -1) { // not matched to any 
                int comp_score = compatibility(students, mentors, i, j);
                matched[j] = i;
                comp_score += solve(students, mentors, matched, i + 1);
                ans = max(ans, comp_score);
                matched[j] = -1;
            }
        }
        return ans;
    } 
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students[0].size(), m = students.size();

        vector<int> matched(m, -1); // mentor i matched to matched[i] student

        return solve(students, mentors, matched, 0);
    }
};
