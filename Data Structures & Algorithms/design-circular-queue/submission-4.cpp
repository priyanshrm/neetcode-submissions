struct Node{
    int val;
    Node* next;

    Node(int v){
        val = v;
        next = nullptr; 
    } 
};
    
class MyCircularQueue {
public:
    Node* head;
    Node* tail;
    int size;
    int cap;

    MyCircularQueue(int k) {
        cap = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node* temp = new Node(value);
        if(isEmpty()){
            head = temp;
            tail = temp;
            temp->next = temp;
            size++;
            return true;
        }
        temp->next = head;
        tail->next = temp;
        tail = temp;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(size == 1){
            delete head;
            tail = head = nullptr;
            size--;
            return true;
        }
        Node* dummy = head;
        tail->next = head->next;
        head = head->next;
        size--;
        delete dummy;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size == cap);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */