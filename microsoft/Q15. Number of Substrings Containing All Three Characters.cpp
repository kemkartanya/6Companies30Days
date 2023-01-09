class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        map<char, int> mp;
        int l = 0, r = 0, e = s.length() - 1;
        while(r < s.length()) {
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']) {
                count += e - r + 1;
                mp[s[l]]--; l++;
            }
            r++;
        }
        return count;
    }
};
