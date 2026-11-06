class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        for(int i = 0; i<nums.size(); i++){
            hash_map[nums[i]]++;
            if(hash_map[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};