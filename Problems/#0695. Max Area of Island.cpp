// Company Amazon
// 20 #0695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxArea = max(maxArea, dfs(grid,i,j));
            }
        }
        
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j] ==0){
            return 0;
        }
        
        grid[i][j] = 0;
        int count = 1;
        count += dfs(grid,i+1,j);
        count += dfs(grid,i-1,j);
        count += dfs(grid,i,j+1);
        count += dfs(grid,i,j-1);
        
        return count;
    }
};