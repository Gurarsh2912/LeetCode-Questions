class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstR = false, firstC = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(i==0) firstR = true;
                    if(j==0) firstC = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstR){
            for(int j = 0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        if(firstC){
            for(int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};