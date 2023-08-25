class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        for(int i=0; i<=k; i++) {  // running for k + 1 times

            vector<int> tempPrices = prices;

            for(int j=0; j<flights.size(); j++) {
                int f = flights[j][0], t = flights[j][1], p = flights[j][2];

                if(prices[f] == INT_MAX) continue;

                if(prices[f] + p < tempPrices[t]) {
                    tempPrices[t] = prices[f] + p;
                }
            }

            prices = tempPrices;
        }

        if(prices[dst] == INT_MAX) return -1;
        else return prices[dst];
    }
};
