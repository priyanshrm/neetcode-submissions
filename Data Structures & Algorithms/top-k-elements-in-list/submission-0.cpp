class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for(auto num: nums){
            hash_map[num]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto [num, freq]: hash_map){
            bucket[freq].push_back(num);
        }
        vector<int> res;
        for(auto i = bucket.end()-1; i>=bucket.begin(); i--){
            for(auto num: *i){
                res.push_back(num);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
