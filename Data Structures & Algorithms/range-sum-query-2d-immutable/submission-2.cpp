class NumMatrix {
public:
    vector<vector<int>> prefix_sum;

    NumMatrix(vector<vector<int>>& matrix) {
        // vector<vector<int>> prefix_sum(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                int k;
                if(i!=0 && j!=0){
                    k = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
                    matrix[i][j] += k;
                    continue;
                }
                if(i!=0){
                    k = matrix[i-1][j];
                    matrix[i][j] += k;
                    continue;
                }
                if(j!=0){
                    k = matrix[i][j-1];
                    matrix[i][j] += k;
                }
            }
        }
        this->prefix_sum = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(max(row1,0)==0 && max(col1,0)==0){
            return prefix_sum[row2][col2];
        }
        if(max(row1,0)==0){
            return prefix_sum[row2][col2] - prefix_sum[row2][col1-1];
        }
        if(max(col1,0)==0){
            return prefix_sum[row2][col2] - prefix_sum[row1-1][col2];
        }

        return prefix_sum[row2][col2] - prefix_sum[row2][col1-1] - prefix_sum[row1-1][col2] + prefix_sum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */