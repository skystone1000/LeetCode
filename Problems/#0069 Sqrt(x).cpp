// Binary Search
// 02 #0069 Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int l = 1, r = x/2;
        while(l<=r){
            int mid = l+(r-l)/2;
            
            long long mult = (long long)mid*mid;
            
            if(mult == x){
                return mid;
            }
            else if(mult < x){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
};
/*
class Solution2 {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        
        long long i=1;
        while(i<x/2){
            i++;
            if(i*i < x){
                continue;
            }else if(i*i > x){
                return i-1;
            }else{
                return i;
            }
        }
        return x/2;
    }
};*/