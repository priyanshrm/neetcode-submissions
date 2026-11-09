class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }

    void push(int x) {
        if(this->q1.empty() && this->q2.empty()){
            q1.push(x);
        } else if(this->q1.empty()){
            q2.push(x);
        } else if(this->q2.empty()){
            q1.push(x);
        } else {
            cout << "Invalid" << endl;
        }
    }
    
    int pop() {
        if(this->q1.empty() && this->q2.empty()){
            cout << "Invalid" << endl;
        } else if(this->q1.empty()){
            int x ;
            while(!q2.empty()){
                x = q2.front();
                q2.pop();
                if(q2.empty()){
                    return x;
                }
                q1.push(x);
            }
        } else if(this->q2.empty()){
            int x;
            while(!q1.empty()){
                x = q1.front();
                q1.pop();
                if(q1.empty()){
                    return x;
                }
                q2.push(x);
            }
        } else {
            cout << "Invalid" << endl;
        }
    }
    
    int top() {
        if(this->q1.empty() && this->q2.empty()){
            cout << "Invalid" << endl;
        } else if(this->q1.empty()){
            int x ;
            while(!q2.empty()){
                x = q2.front();
                q2.pop();
                q1.push(x);
                if(q2.empty()){
                    return x;
                }
            }
        } else if(this->q2.empty()){
            int x;
            while(!q1.empty()){
                x = q1.front();
                q1.pop();
                q2.push(x);
                if(q1.empty()){
                    return x;
                }
            }
        } else {
            cout << "Invalid" << endl;
        }
    }
    
    bool empty() {
        return (this->q1.empty() && this->q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */