// Search array 06
// #1252 Cells with Odd Values in a Matrix

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        // Initialise mat[n][m] with all values 0
        vector<vector<int>> finMat;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                temp.push_back(0);
            }
            finMat.push_back(temp);
        }
        
        // Increment 1 for each row and col
        for(int i=0;i<indices.size();i++){
            int r=indices[i][0];
            int c=indices[i][1];
            for(int j=0;j<m;j++){
                finMat[r][j]++;
            }
            for(int j=0;j<n;j++){
                finMat[j][c]++;
            }
        }
        
        // Count odds
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<finMat[i][j]<<" ";
                if(finMat[i][j] % 2 != 0)
                    count++;
            }
            // cout<<endl;
        }
        
        return count;
    }
};