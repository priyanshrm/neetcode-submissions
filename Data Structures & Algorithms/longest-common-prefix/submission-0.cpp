class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k = 201;
        string k_str = "";
        for(string item: strs){
            if(item.size()<k){
                k = item.size();
                k_str = item;
            }
        }
        int first_uncommon_index = k;
        for(int i = 0; i<k; i++){
            char curr_char = k_str[i];
            for(string item: strs){
                if(curr_char != item[i]){
                    first_uncommon_index = i;
                    return k_str.substr(0, i);
                }
            }
        }
        return k_str;
        
    }
};