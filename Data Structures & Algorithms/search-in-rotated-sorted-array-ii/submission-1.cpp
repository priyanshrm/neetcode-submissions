class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return true;
            if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                continue;
            }
            if(nums[i] <= nums[mid]){
                if(nums[i] <= target && target < nums[mid]){
                    // int k = nums[j];
                    j = mid - 1;
                    // while(nums[j]==k && j>i){
                    //     j--;
                    // }
                } else {
                    // int k = nums[i];
                    i = mid + 1;
                    // while(nums[i]==k && i<j){
                    //     i++;
                    // }
                }
            } else {
                if(nums[mid] < target && target <= nums[j]){
                    // int k = nums[i];
                    i = mid + 1; 
                    // while(nums[i]==k && i<j){
                    //     i++;
                    // }
                } else {
                    // int k = nums[j];
                    j = mid - 1;
                    // while(nums[j]==k && j>i){
                    //     j--;
                    // }
                }
            } 
        }
        return false;
    }
};