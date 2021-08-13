// Binary Search
// 05 #0278 First Bad Version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n-1;
        if(n <= 0 || isBadVersion(0)) return 0;
                
        while(left <= right){
            int mid = l + (r-l)/2;
            bool check = isBadVersion(mid);
            
            if(check == false){
                l = mid + 1;
            }else{
                if(isBadVersion(mid-1) == false){
                    return mid;
                }
                r = mid - 1; 
            }
        }
        return r;
        
    }
};