class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(min_stk.empty() || val <= min_stk.top()){
            min_stk.push(val);
        }
        stk.push(val);
    }
    
    void pop() {
        if(stk.top() == min_stk.top()){
            min_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
