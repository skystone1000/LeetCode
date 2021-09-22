// Company Amazon
// 04 #0657 Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'U')
                x++;
            else if(moves[i] == 'D')
                x--;
            else if(moves[i] == 'L')
                y--;
            else if(moves[i] == 'R')
                y++;
        }
        
        if(x==0 && y==0) 
            return true;
        else 
            return false;
        
    }
};