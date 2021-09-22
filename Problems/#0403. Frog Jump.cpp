// Company Amazon
// 21 #0403. Frog Jump
// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        for(int i=3;i<stones.size();i++){
            if(stones[i] > stones[i-1] * 2){
                return false;
            }
        }
        
        set<int> stonePositions;
        for(int stone:stones){
            stonePositions.insert(stone);
        }
        
        int lastStone = stones[stones.size()-1];
        stack<int> positions;
        stack<int> jumps;
        positions.push(0);
        jumps.push(0);
        
        while(!positions.empty()){
            int position = positions.top();
            positions.pop();
            int jumpDistance = jumps.top();
            jumps.pop();
            for(int i=jumpDistance-1 ; i<=jumpDistance+1 ; i++){
                if(i <= 0) {
                    continue;
                }

                int nextPosition = position + i;
                if(nextPosition == lastStone) {
                    return true;
                } else if (stonePositions.count(nextPosition) > 0) {
                    positions.push(nextPosition);
                    jumps.push(i);
                }
            }
        }
        
        return false;
    }
};