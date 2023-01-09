class Solution {
public:
    class compare {
        public:
        bool operator()(vector<int> a, vector<int> b) {
            if(a[0] != b[0]) return a[0] > b[0];
            else return a[1] > b[1];
        }
    };
    int dist(vector<int> p1, vector<int> p2) {
        return sqrt((p1[1] - p2[1]) * (p1[1] - p2[1]) + (p1[0] - p2[0]) * (p1[0] - p2[0]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        compare cmp;
        sort(p.begin(), p.end(), cmp);

        if(dist(p[0], p[1]) == dist(p[1], p[3]) && dist(p[1], p[3]) == dist(p[3], p[2]) && dist(p[3], p[2]) == dist(p[2], p[0]) && dist(p[1], p[2]) == dist(p[0], p[3]) && dist(p[0], p[1]) > 0)
        return true;
        else
        return false;
    }
};
