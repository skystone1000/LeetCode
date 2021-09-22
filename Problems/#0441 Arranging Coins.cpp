// #0441 Arranging Coins

class Solution {
public:
    int arrangeCoins(int n) {
        
        if(n==0) return 0;
        
        long long row = 0;
        while(n >= row+1){
            row++;
            n = n - row;
        }
        return row;
    }
};
