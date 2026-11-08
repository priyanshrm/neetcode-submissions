class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(auto ch: s){
            
            if(ch==')' && stck.size()>0){
                if(stck.top()!='(') return false;
                stck.pop();
            } else if(ch == ']' && stck.size()>0){
                if(stck.top()!='[') return false;
                stck.pop();
            } else if(ch == '}' && stck.size()>0){
                if(stck.top()!='{') return false;
                stck.pop();
            } else {
                stck.push(ch);
            }
        }
        if(stck.size() == 0) return true;
        return false;
    }
};
