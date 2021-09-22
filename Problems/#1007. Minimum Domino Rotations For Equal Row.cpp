// Company Amazon
// 50 #1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // Setting Complete Vector A with A[0]
        // numSwaps(A[0], A, B)
        
        int minSwaps = min(
            numSwaps(A[0], A, B), numSwaps(B[0], A, B)
        );
        
        minSwaps = min(minSwaps, numSwaps(A[0], B, A));
        minSwaps = min(minSwaps, numSwaps(B[0], B, A));
        
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
    
    int numSwaps(int target, vector<int> A, vector<int> B){
        int swaps = 0;
        for(int i=0;i<A.size();i++){
            if(A[i] != target && B[i] != target){
                return INT_MAX;
            } else if(A[i] != target){
                swaps++;
            }
        }
        return swaps;
    }
};