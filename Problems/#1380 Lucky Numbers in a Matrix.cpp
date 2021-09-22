// Search array 11
// #1380 Lucky Numbers in a Matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luc;
        for(int i=0;i<matrix.size();i++){
            // Finding Least in row
            int least = matrix[i][0];
            int col = 0;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] < least){
                    least = matrix[i][j];
                    col = j;
                    
                }
            }

            // Checking if that least is max in col
            int row = i;
            int greatest = least; 
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][col] > greatest){
                    greatest = matrix[j][col];
                    row = j;
                }
            }
            
            // If yes add to Lucky
            if(row == i){
                luc.push_back(least);
            }
        }
        return luc;
    }
};