// Search array 05
// #1266 Minimum Time Visiting All Points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i=0;i<points.size()-1;i++){
            int x1 = points[i][0];
            int x2 = points[i+1][0];
            int y1 = points[i][1];
            int y2 = points[i+1][1];
            
            int x = abs(x1 - x2);
            int y = abs(y1 - y2);
            
            
            if(x>y){
                time = time + x;
            }else{
                time = time + y;
            }
        }
        return time;
    }
};