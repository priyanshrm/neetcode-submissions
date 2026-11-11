class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;

            int k = i+1, j = nums.size()-1;
            while(k < j){
                if(nums[i] + nums[k] + nums[j] < 0){
                    k++;
                } else if(nums[i] + nums[k] + nums[j] > 0) {
                    j--;
                } else {
                    res.push_back({nums[i], nums[k], nums[j]});
                    k++;
                    j--;
                    while(k<j && nums[k-1]==nums[k]) k++;
                    while(k<j && nums[j+1]==nums[j]) j--;
                    
                }
            }
        }
        return res;
    }
};
