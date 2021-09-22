// Company Amazon
// 03 #0231 Power of Two
// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // Method 1 - TLE
        /*
        while(n%2 == 0){
            n = n/2;
        }
        
        if(n==1){
            return true;
        }else{
            return false;
        }*/
        
        
        // Method 2
        /*
        int oneBits = 0;
        while(n>0){
            if((n & 1) == 1){
                oneBits++;
                if(oneBits > 1)
                    return false;
            }
            
            n = n>>1;
        }
        
        // return oneBits == 1;
        if(oneBits == 1){
            return true;
        }else{
            return false;
        }*/
        
        
        // Method 3
        if(n<=0)
            return false;
        if((n & (n-1)) == 0)
            return true;
        else
            return false;
    }
};