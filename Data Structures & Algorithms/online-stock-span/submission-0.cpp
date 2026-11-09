class StockSpanner {
public:
    stack<int> stk1;
    stack<int> stk2;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!stk1.empty() && stk1.top() <= price){
            span++;
            stk2.push(stk1.top());
            stk1.pop();
        }
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */