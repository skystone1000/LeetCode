// Company Amazon
// #1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i,j=0;
        for(i = 0; i < A.size(); i++){
            if(A[i] == 0)
                K--;
            if(K<0){
                if(A[j] == 0)
                    K++;
                j++;
            }
        }
        
        return i-j;
    }
};