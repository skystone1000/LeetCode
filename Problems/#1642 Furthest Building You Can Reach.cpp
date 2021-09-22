// April Challenge 2021 - Day 26 
// #1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        priority_queue<int> max_heap;
        for(i=0;i<heights.size()-1;i++){
            int diff = heights[i+1] - heights[i];
            if(diff <= 0){
                continue;
            } else {
                if(diff <= bricks){
                    bricks -= diff;
                    max_heap.push(diff);
                } else if(ladders > 0){
                    if(max_heap.size()){
                        int currMaxBricks = max_heap.top();
                        if(currMaxBricks > diff){
                            bricks += currMaxBricks;
                            max_heap.pop();
                            max_heap.push(diff);
                            bricks -= diff;
                        }    
                    }
                    ladders--;
                } else {
                    return i;
                }
            }
        }
        return i;
    }
};