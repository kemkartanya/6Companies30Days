class StockPrice {
public:
    set<pair<int, int>> s;
    map<int, int> m;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m.find(-timestamp) != m.end()) {
            s.erase({m[-timestamp], -timestamp});
        }
        m[-timestamp] = price;
        s.insert({price, -timestamp});
    }
    
    int current() {
        return m.begin()->second;
    }
    
    int maximum() {
        return s.rbegin()->first;
    }
    
    int minimum() {
        return s.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
