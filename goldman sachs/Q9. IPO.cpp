class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> v;
        for(int i=0; i<profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());

        priority_queue<int> pq;  //maxHeap
        int i = 0;
        while(i<v.size() && k) {
            if(v[i].first <= w) {
                pq.push(v[i++].second);
            } else {
                if(!pq.empty()) {
                    w += pq.top();
                    pq.pop();
                    k--;
                } else {
                    return w;
                }
            }
        }

        while(!pq.empty() && k) {
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};
