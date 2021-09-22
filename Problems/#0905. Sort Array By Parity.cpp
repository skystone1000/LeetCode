// Company Amazon
// 31 #0905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even = 0;
        for(int i=0;i<A.size();i++){
            if(A[i] % 2 == 0){
                swap(A[even], A[i]);
                even++;
            }
        }
        return A;
    }
};

/*
// LeetCode arrays 12
// #905 Sort Array By Parity 

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
*/