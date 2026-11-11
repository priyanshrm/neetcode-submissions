class Solution {
public:
    bool isPalindrome(string s) {
        string q = "";
        for(auto ch: s){
            if((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'z')){
                q+=tolower(ch);
            }
        }
        auto start_ptr = q.begin();
        auto end_ptr = q.end() - 1;
        while(start_ptr < end_ptr){
            
            if(*start_ptr != *end_ptr){
                return false;
            }
            start_ptr++;
            end_ptr--;
        }
        return true;
    }
};
