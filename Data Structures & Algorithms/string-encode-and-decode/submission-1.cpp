class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto str: strs){
            s += to_string(str.size());
            s += "#";
            s += str;
        }
        return s;
    }


    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i<s.size()){
            int k;
            string key = "";
            while(s[i] >= '0' && s[i] <= '9'){
                key += s[i];
                i++;
                if(s[i]=='#'){
                    k = stoi(key);
                }
            }
            strs.push_back(s.substr(i+1,k));
            i += k+1;

        }
        return strs;
    }
};
