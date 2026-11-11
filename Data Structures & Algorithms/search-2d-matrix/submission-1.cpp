class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size()-1;
        int c = matrix[0].size()-1;
        while(i<j){
            int mid = i + (j-i)/2;
            if(matrix[mid][c] < target){
                if(matrix[mid][0] > target){
                    i = mid;
                } else if(matrix[mid][0] < target) {
                    i = mid + 1;
                } else {
                    return true;
                }
            } else if(matrix[mid][c] > target){
                if(matrix[mid][0] > target){
                    j = mid - 1;
                } else if(matrix[mid][0] < target) {
                    j = mid;
                } else {
                    return true;
                }
            } else {
                return true;
            }
        }
        int k = 0;
        while(k<=c){
            int mid = k + (c-k)/2;
            if(matrix[i][mid] < target){
                k = mid + 1;
            } else if(matrix[i][mid] > target){
                c = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
