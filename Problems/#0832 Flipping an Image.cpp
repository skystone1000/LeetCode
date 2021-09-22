// Search array 07
// #0832 Flipping an Image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            int start = 0,end = A[i].size()-1;
            while(start<=end){
                int temp = A[i][start];
                A[i][start] = A[i][end];
                A[i][end] = temp;
                start++;
                end--;
            }
        }
        
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j] == 1){
                    A[i][j] = 0;
                }else{
                    A[i][j] = 1;
                }
            }
        }
        return A;
    }
};