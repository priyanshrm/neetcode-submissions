class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min_idx = min(word1.size(), word2.size());
        int i = 0, j = 0;
        string temp = "";
        while(i < min_idx && j < min_idx){
            temp += word1[i++];
            temp += word2[j++];
        }
        while(i<word1.size()){
            temp += word1[i++];
        }
        while(j<word2.size()){
            temp += word2[j++];
        }
        return temp;
    }
};