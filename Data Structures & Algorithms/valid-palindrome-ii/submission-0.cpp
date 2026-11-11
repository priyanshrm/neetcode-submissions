class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        int i = start, j = end;
        while(i<j){
            // if(i==x) {
            //     i++;
            //     continue;
            // }
            // if(j==x) {
            //     j++;
            //     continue;
            // }
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;

    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i]!=s[j]){
                bool left = isPalindrome(s, i+1, j);
                bool right = isPalindrome(s, i, j-1);
                return (right || left);
            }
            i++;
            j--;
        }
        return true;
    }
};