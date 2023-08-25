class Solution {
public:
    int solve(string s, vector<string> prev, int i) {

        if(i >= s.length()) return 0;

        int ans = 0;

        for(int j=i; j<s.length(); j++) {
            string sub = s.substr(i, j - i + 1);

            bool unique = true;
            for(string x: prev) {
                if(x == sub) {
                    unique = false;
                    break;
                }
            }

            if(!unique) continue;

            prev.push_back(sub);
            ans = max(ans, 1 + solve(s, prev, j + 1));
            prev.pop_back();
            
        }

        return ans;
    }
    int maxUniqueSplit(string s) {
        vector<string> prev;
        return solve(s, prev, 0);
    }
};
