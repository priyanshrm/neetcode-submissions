class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> cost = arr;
        for(auto& n: cost){
            n = abs(n - x);
        }
        int i = 0;
        int sum = 0;
        int min_sum = INT_MAX;
        int min_i = 0;
        for(int j = 0; j<cost.size(); j++){
            sum += cost[j];
            if(j-i+1 == k){
                if(min_sum > sum){
                    min_i = i;
                    min_sum = sum;
                }
                sum -= cost[i];
                i++;
            }
        }

        return vector<int>(arr.begin()+min_i, arr.begin()+min_i+k);

    }
};