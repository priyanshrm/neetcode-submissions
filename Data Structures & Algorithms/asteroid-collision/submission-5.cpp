class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto num: asteroids){
            if(stk.empty() || stk.top()*num > 0 || (stk.top()<0 && num>0)){
                stk.push(num);
                continue;
            }
            bool isAlive = true;

            while(!stk.empty() && stk.top()>0 && num<0 && isAlive){
                if(abs(stk.top()) == abs(num)){
                    stk.pop();
                    isAlive = false;
                } else if(abs(stk.top()) < abs(num)) {
                    stk.pop();
                    isAlive = true;
                } else {
                    isAlive = false;
                }
            }

            if(isAlive){
                stk.push(num);
            }
        }
        vector<int> res;
        stack<int> stk_rev;
        while(!stk.empty()){
            stk_rev.push(stk.top());
            stk.pop();
        }
        while(!stk_rev.empty()){
            res.push_back(stk_rev.top());
            stk_rev.pop();
        }
        return res;
    }
};