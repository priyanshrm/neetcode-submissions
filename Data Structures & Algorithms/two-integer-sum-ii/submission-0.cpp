class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash_map;
        vector<int> res;
        for(int i = 0; i<numbers.size(); i++){
            if(hash_map.contains(target - numbers[i])) {
                res.push_back(min(hash_map[target - numbers[i]] + 1,i + 1));
                res.push_back(max(hash_map[target - numbers[i]] + 1,i + 1));
                break;
            }       
            hash_map[numbers[i]] = i;
        }
        return res;
    }
};
