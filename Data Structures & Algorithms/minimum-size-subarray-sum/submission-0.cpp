class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int min_length = INT_MAX;
        int sum = 0;
        for(int j = 0; j<nums.size(); j++){
            sum += nums[j];
            while(sum >= target && i<=j){
                min_length = min(min_length, j-i+1);
                sum -= nums[i];
                i++;
                // cout << min_length << endl;            
            }
        }
        if (min_length == INT_MAX) return 0;
        return min_length;
    }
};