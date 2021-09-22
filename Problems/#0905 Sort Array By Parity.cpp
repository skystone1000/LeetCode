// LeetCode arrays 13
// #0905 Sort Array By Parity 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        vector<int> ans;
        ans.reserve(n);
        
        for(int i=0;i<n;i++){
            if(A[i] % 2 == 0){
                ans.push_back(A[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(A[i] % 2 == 1){
                ans.push_back(A[i]);
            }
        }
        return ans;
    }
};