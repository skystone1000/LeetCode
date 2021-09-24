// LeetCode arrays 9
// #0941 Valid Mountain Array  

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        
        if(n < 3){
            return false;
        }
        
        // Find max;
        int max = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            if(A[i] > max){
                max = A[i];
                index = i;
            }
        }
        
        // Check if only increasing or decreasing
        if(index == 0 || index == n-1){
            return false;
        }
        
        
        // Check Increasing
        // int flag = 0 ;
        for(int i=1;i<=index;i++){
            if(A[i] > A[i-1]){
                continue;
            }else{
                // flag = 1;
                // break;
                return false;
            }
        }
        
        // Check Decreasing
        for(int i=index;i<n-1;i++){
            if(A[i] > A[i+1]){
                continue;
            }else{
                // flag = 1;
                // break;
                return false;
            }
        }
        
        return true;
        
    }
};