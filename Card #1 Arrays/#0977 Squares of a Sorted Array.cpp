// LeetCode arrays 3
// #0977 Squares of a Sorted Array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i=0;i<A.size();i++){
            int temp = A[i];
            A[i] = temp * temp;
        }
        sort(A.begin(),A.end());
        return A;
    }
};