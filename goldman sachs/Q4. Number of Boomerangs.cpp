class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();
        for(int i=0; i<n; i++) {
            unordered_map<int, int> mp;
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                mp[(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])]++;
            }
            for(auto it: mp) {
                count += it.second * (it.second - 1);
            }
        }
        return count;
    }
};
