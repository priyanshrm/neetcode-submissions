class MyHashSet {
public:
    vector<int> my_vec;
    MyHashSet() {
    }
    
    void add(int key) {
        this->my_vec.push_back(key);
    }
    
    void remove(int key) {
        // for(int i = 0; i<this->my_vec.size(); i++){
        //     if(this->my_vec[i]==key) {
        //         this->my_vec.erase(this->my_vec.begin() + i);
        //     }
        // }
        erase(my_vec, key);
        
    }
    
    bool contains(int key) {
        for(int i = 0; i<this->my_vec.size(); i++){
            if(this->my_vec[i]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */