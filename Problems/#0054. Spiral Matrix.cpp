// Company Amazon
// AIE 10.9 #0054. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row = matrix.size();
        if(row <= 0) return v;
        int col = matrix[0].size();
        if(col <= 0) return v;
        
        int r,c;
        for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        //top
        for(int i=c; i<col-c; i++){
            v.push_back(matrix[r][i]);
        }
        //right
        for(int i=r+1; i<row-r; i++){
            v.push_back(matrix[i][col-c-1]);
        }
        //bottom
        for(int i=col-c-2; row-r-1>r && i>=c; i--){
            v.push_back(matrix[row-r-1][i]);
        }
        //left
        for(int i=row-r-2; col-c-1>c && i>r; i--){
            v.push_back(matrix[i][c]);
        }
        
    }
    return v;
    }
};