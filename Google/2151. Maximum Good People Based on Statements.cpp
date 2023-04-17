class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0, n = statements.size();
       for(int i=0; i<(1 << n); i++) {
           bool flag = true;
           for(int j=0; j<n; j++) {
               if(!(i & (1 << j))) continue; // bad person - don't care
               
               for(int k=0; k<n; k++) { // statements by good person
                    if(((i & (1 << k)) && statements[j][k] == 0) || (!(i & (1 << k)) && statements[j][k] == 1)) {
                        flag = false;
                        break;
                    }     
               }
                if(!flag) break;
           }
           if(flag) ans = max(ans, __builtin_popcount(i));
       } 
       return ans;
    }
};
