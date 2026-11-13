class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char, int> hash_map;
        int max_length = 0;
        pair<int, int> sub;
        sub.first = 0;
        for(int i = 0; i <s.size(); i++){
            if(hash_map.contains(s[i]) && hash_map[s[i]]>=sub.first){
                max_length = max(max_length, sub.second - sub.first + 1);
                sub.first = hash_map[s[i]] + 1;
            }
            hash_map[s[i]] = i;
            sub.second = i;
        }
        max_length = max(max_length, sub.second - sub.first + 1);
        
        
        
        return max_length;
    }
};
