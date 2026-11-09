class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk_num;
        stack<int> stk_idx;
        vector<int> res(temperatures.size(),0);
        for(int i = 0; i<temperatures.size(); i++){
            while(!stk_num.empty() && temperatures[i] > stk_num.top()){
                res[stk_idx.top()] = (i-stk_idx.top());
                stk_num.pop();
                stk_idx.pop();
            }
            stk_num.push(temperatures[i]);
            stk_idx.push(i);
        }

        return res;
    }
};
