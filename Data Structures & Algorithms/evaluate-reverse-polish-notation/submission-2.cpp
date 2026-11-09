class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto val: tokens){
            if(val == "+"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x+y);
            } else if(val == "-"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y-x);
            } else if(val == "*"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x*y);
            } else if(val == "/"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y/x);
            } else {
                stk.push(stoi(val));
            }
        }
        if(stk.empty()) return 0;
        return stk.top();
    }
};
