class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(auto ch: s1){
            freq[ch - 'a']++;
        }
        vector<int> freq2(26,0);
        int i = 0;
        for(int j = 0; j<s2.size(); j++){
            freq2[s2[j]-'a']++;
            if(j-i+1 > s1.size()){
                freq2[s2[i] - 'a']--;
                i++;
            }
            if(freq == freq2) return true;
        }
        return false;
    }
};
