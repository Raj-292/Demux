// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int, int>> monotonic_stack;
    int pos;
    StockSpanner() {
        pos = 0;
    }
    
    int next(int price) {
        pos++;
        while(!monotonic_stack.empty() && monotonic_stack.top().second <= price)
            monotonic_stack.pop();
        
        int res = (monotonic_stack.empty())? pos: pos - monotonic_stack.top().first;
        
        monotonic_stack.push({pos, price});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */