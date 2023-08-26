class Solution {
public:
    typedef pair<string, int> dt;
    class comparator {
        public:
        bool operator()(const pair<string, int>& i1, const pair<string, int>& i2) {
            if(i1.second > i2.second) return true;
            else if(i1.second == i2.second){
                if(i1.first < i2.first) return true;
            }
            return false;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(int i=0; i<words.size(); i++) {
            mp[words[i]]++;
        }

        // vector<pair<string, int>> v;
        // for(auto i : mp) {
        //     v.push_back({i.first, i.second});
        // }

        comparator cmp;
        // sort(v.begin(), v.end(), cmp);

        // vector<string> ans;
        // for(int i=0; i<k; i++) {
        //     ans.push_back(v[i].first);
        // }
        // return ans;
        priority_queue<dt, vector<dt>, comparator> pq;

        for(auto i : mp) {
            pq.push({i.first, i.second});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
