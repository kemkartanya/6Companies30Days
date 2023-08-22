class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        string s1, s2, s3, s4, res;
        s1 = s2 = s3 = s4 = res;

        for(int i=0; i<s.length(); i++) {
            for(int j=i+1; j<s.length(); j++) {
                for(int k=j+1; k<s.length(); k++) {
                    s1 = s.substr(0, i);
                    s2 = s.substr(i, j-i);
                    s3 = s.substr(j, k-j);
                    s4 = s.substr(k);

                    if(s1.size() == 0 || s2.size() == 0 || s3.size() == 0 || s4.size() == 0) continue;

                    if(stoll(s1) > 255 || s1[0] == '0' && s1.size() > 1) continue;
                    if(stoll(s2) > 255 || s2[0] == '0' && s2.size() > 1) continue;
                    if(stoll(s3) > 255 || s3[0] == '0' && s3.size() > 1) continue;
                    if(stoll(s4) > 255 || s4[0] == '0' && s4.size() > 1) continue;

                    res = s1 + "." + s2 + "." + s3 + "." + s4;
                    ans.push_back(res);
                }
            }
        }

        return ans;
    }
};
