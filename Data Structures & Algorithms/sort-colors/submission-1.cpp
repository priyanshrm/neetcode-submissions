class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        vector<int> a;
        int i = l, j = mid + 1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                a.push_back(nums[i]);
                i++;
            } else {
                a.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            a.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            a.push_back(nums[j]);
            j++;
        }
        for(int k = 0; k<a.size(); k++){
            nums[k + l] = a[k];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r){
        if(l==r) return;
        int mid = l + (r - l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
    }
};