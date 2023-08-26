class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        
        map<char, vector<int>> m;
        for(int i=0; i<s.length(); i++) 
            m[s[i]].push_back(i);

        for(auto w : words) {
            int latest = -1;
            for(int j=0; j<w.length(); j++) {
                auto it = upper_bound(m[w[j]].begin(), m[w[j]].end(), latest);
                if(it == m[w[j]].end()) break;
                latest = *it;
                if(j == w.length() - 1) count++;
            }
        }

        return count;
    }
};
