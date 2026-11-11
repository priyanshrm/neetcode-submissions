class Solution {
public:
    void reverseString(vector<char>& s) {
        auto start_ptr = s.begin();
        auto end_ptr = s.end() - 1;
        while(start_ptr < end_ptr){
            swap(*start_ptr, *end_ptr);
            start_ptr++;
            end_ptr--;
        }
    }
};