class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int depth = n/2;
        for(int j=0; j<depth; j++){
            for(int i=0; i<n-1-2*j; i++){   //注意每多一层，i的值也要变
                int temp = matrix[0+j][i+j];
                matrix[0+j][i+j] = matrix[n-i-1-j][0+j];    //先只写一层的，然后再加j
                matrix[n-i-1-j][0+j] = matrix[n-1-j][n-i-1-j];
                matrix[n-1-j][n-i-1-j] = matrix[i+j][n-1-j];
                matrix[i+j][n-1-j]=temp;
            }
        }
    }
};