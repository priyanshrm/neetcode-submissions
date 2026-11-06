class Solution {
public:
    string getKey(string str){
        vector<int> hash_key(26,0);
        for(char ch: str){
            hash_key[ch - 'a']++;
        }
        string key = "";
        for(int val: hash_key){
            key += "#";
            key += val;
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i = 0;
        unordered_map<string, int> hash_map;
        vector<vector<string>> res;
        for(string str: strs){
            string key = getKey(str);
            if(hash_map.contains(key)){
                res[hash_map[key]].push_back(str);
            } else {
                hash_map[key] = i;
                vector<string> k = {str};
                res.push_back(k);
                i++;
            }
        }
        return res;
    }
};
