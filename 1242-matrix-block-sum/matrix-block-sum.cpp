class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(); // size of row
        int n = mat[0].size(); // size of column 

        //initialize m*n 2D matrix field with zeroes 
        vector<vector<int>>answer(m, vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int sum = 0;

                for(int r = i-k;r<=i+k;r++){
                    for(int c = j-k;c<=j+k;c++){
                        if (r >= 0 && r < m && c >= 0 && c < n) {
                            sum += mat[r][c];
                        }
                    }
                }
                answer[i][j] = sum;
            }
        }
        return answer;
    }
};