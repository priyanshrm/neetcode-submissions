class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash_map;
        for(int i = 0; i<nums.size(); i++){
            if(hash_map.contains(target - nums[i])){
                int k = hash_map[target - nums[i]][0];
                vector<int> res = {min(i, k), max(i, k)};
                return res;
            } else {
                hash_map[nums[i]] = {i};
            }
        }
    }
};
