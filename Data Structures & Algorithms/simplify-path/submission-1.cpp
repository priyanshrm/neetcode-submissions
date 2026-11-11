class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int size = 0;
        string temp = "/";
        for(auto ch: path){
            if(ch != '/'){
                temp += ch;
            } else {
                if(temp != "/"){
                    stk.push(temp);
                    size++;
                    if(stk.top()=="/.."){
                        stk.pop();
                        size--;
                        if(size>0){
                            stk.pop();
                            size--;
                        }
                        
                    }
                    if(size > 0 && stk.top()=="/."){
                        stk.pop();
                        size--;
                    }
                    temp = "/";
                }
            }
            
        }
        if(temp != "/"){
            stk.push(temp);
            size++;
            if(stk.top()=="/.."){
                stk.pop();
                size--;
                if(size>0){
                    stk.pop();
                    size--;
                }
                
            }
            if(size > 0 && stk.top()=="/."){
                stk.pop();
                size--;
            }
            temp = "/";
        }



        stack<string> temp_stk;
        while(!stk.empty()){
            
            temp_stk.push(stk.top());
            stk.pop();
        }
        string r = "";
        while(!temp_stk.empty()){
            r += temp_stk.top();
            temp_stk.pop();
        }

        if(r=="") return "/";

        return r;
    }
};