class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26] = {0};
        string rem = "";
        
        for(char c: order) arr[c-'a']++;

        for(char c: s) {
            if(arr[c-'a'] == 0) rem += c;
            else arr[c-'a']++;
        }

        string ans;
        for(char c: order) {
            while(arr[c-'a'] > 1) {
                ans += c;
                arr[c-'a']--;
            } 
        }
        ans += rem;
        return ans;
    }
};
