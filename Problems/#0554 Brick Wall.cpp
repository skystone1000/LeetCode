// April Challenge 2021 - Day 22
// #0554. Brick Wall
// https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size(), maxBrickEdges = 0;
        unordered_map<int, int> edgesFrequency;
        for(vector<int> row : wall) {
            int idx = 0; 
            for(int i = 0; i < row.size() - 1; i++) {
                idx += row[i];
                edgesFrequency[idx]++;
                
                maxBrickEdges = max(maxBrickEdges, edgesFrequency[idx]);
            }
        }         
        return rows - maxBrickEdges;
    }
};