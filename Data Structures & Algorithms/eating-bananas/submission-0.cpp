class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int i = 1, j = *max_element(piles.begin(), piles.end());;
        
        while(i<=j){
            int k = i + (j-i)/2;
            int l = 0; 
            for(int i = 0; i<piles.size(); i++){
                l += piles[i]/k + (piles[i]%k != 0);
                if(l>h) break;
            }
            if(l>h){
                i = k + 1;
            } else {
                j = k - 1;
            }
        }

        return min(i+1,j+1);
    }
};
