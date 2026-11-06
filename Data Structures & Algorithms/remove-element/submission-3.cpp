class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        auto start_ptr = nums.begin();
        auto end_ptr = nums.end();
        while(start_ptr<end_ptr){
            if(*start_ptr == val){
                end_ptr--;                
                swap(*start_ptr, *end_ptr);
            } else {
                start_ptr++;
            }
        }
        
        return start_ptr - nums.begin();
    }
};