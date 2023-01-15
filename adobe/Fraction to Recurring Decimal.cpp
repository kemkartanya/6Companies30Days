class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if(numerator == 0) return ans = "0";
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) 
        ans += "-";

        numerator = abs(numerator), denominator = abs(denominator);
        long long int q = numerator / denominator, r = numerator % denominator;
        ans += to_string(q);
        if(r == 0) return ans;
        ans += ".";
        
        map<long long int, int> m;
        while(r) {
            if(m.find(r) != m.end()) {
                int p = m[r];
                ans.insert(p, "(");
                ans.push_back(')');
                break;
            } else {
                m[r] = ans.length();
                r *= 10;
                q = r / denominator;
                r = r % denominator;
                ans.push_back(q + '0');
            }
        }
        return ans;
    }
};
