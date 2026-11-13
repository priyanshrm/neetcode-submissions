class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_length = 0;
        int i = 0;
        int max_freq = 0;
        vector<int> freq(26,0);
        for(int j = 0; j<s.size(); j++){
            freq[s[j]-'A']++;
            max_freq = max(max_freq, freq[s[j] - 'A']);
            if(j - i + 1 > max_freq + k){
                freq[s[i] - 'A']--;
                i++;
            }
            max_length = max(max_length, j - i + 1);
        }
        return max_length;

    }
};
