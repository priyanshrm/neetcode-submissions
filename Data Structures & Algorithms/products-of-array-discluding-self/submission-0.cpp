class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_prod(nums.size(), 1);
        vector<int> suffix_prod(nums.size(), 1);
        for(int i = 1; i<nums.size(); i++){
            prefix_prod[i] = nums[i-1]*prefix_prod[i-1];
        }
        for(int i = nums.size()-2; i>=0; i--){
            suffix_prod[i] = nums[i+1]*suffix_prod[i+1];
        }
        for(int i = 0; i<suffix_prod.size(); i++){
            suffix_prod[i] *= prefix_prod[i];
        }
        return suffix_prod;
    }
};
