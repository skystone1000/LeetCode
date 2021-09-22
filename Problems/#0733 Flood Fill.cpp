// Company Amazon
// 14 #0733 Flood Fill
// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        
        flood_fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void flood_fill(vector<vector<int>> &image, int sr, int sc, int color, int newColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size() || image[sr][sc] != color){
            return ;
        }
        
        image[sr][sc] = newColor;
        flood_fill(image, sr+1, sc, color, newColor);
        flood_fill(image, sr-1, sc, color, newColor);
        flood_fill(image, sr, sc+1, color, newColor);
        flood_fill(image, sr, sc-1, color, newColor);
    }
}; 