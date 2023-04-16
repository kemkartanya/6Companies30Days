class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> set;
        string temp = s.substr(0, k);
        set.insert(temp);
        int n = s.length();

        for(int i=k; i<n; i++) {
            temp.erase(temp.begin());
            temp.push_back(s[i]);
            set.insert(temp);
        }

        return set.size() == pow(2, k);
    }
};
