// Company Amazon
// 41 #0064. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int arr[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i == 0 && j == 0){
                    arr[i][j] = grid[i][j];
                    continue;
                }
                if(i == 0){
                    arr[i][j] = arr[i][j-1] + grid[i][j];
                    continue;
                }
                if(j == 0){
                    arr[i][j] = arr[i-1][j] + grid[i][j];
                    continue;
                }
                arr[i][j] = min(arr[i-1][j]+grid[i][j] , arr[i][j-1]+grid[i][j]);
            }
        }
        
        return arr[grid.size() - 1][grid[0].size() - 1];
    }
};