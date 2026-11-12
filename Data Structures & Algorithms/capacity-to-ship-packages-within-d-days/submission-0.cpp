class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int i = *max_element(weights.begin(), weights.end()),
        j = accumulate(weights.begin(), weights.end(), 0);
        while(i<=j){
            int k = i + (j-i)/2;
            int time = 0;
            int sum = 0;
            for(int l = 0; l<weights.size(); l++){
                sum += weights[l];
                if(sum>k){
                    time++;
                    sum = weights[l];
                }
                if(time>days) break;
            }
            time++;
            if(time > days){
                i = k + 1;
            } else {
                j = k - 1;
            }
        }
        return min(i+1,j+1);
    }
};