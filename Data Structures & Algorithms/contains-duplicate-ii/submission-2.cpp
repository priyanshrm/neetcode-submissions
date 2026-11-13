class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash_map;
        for(int i = 0; i<nums.size(); i++){
            if(hash_map.contains(nums[i])){
                if(i - hash_map[nums[i]] <= k) return true;
                hash_map[nums[i]] = i;
            } else {
                hash_map[nums[i]] = i;
            }
        }
        return false;
    }
};