class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<int,int> hash_map;

        for(int i = 0; i<s.size(); i++){
            hash_map[s[i]]++;
        }
        for(int i = 0; i<t.size(); i++){
            if(hash_map[t[i]]){
                hash_map[t[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
