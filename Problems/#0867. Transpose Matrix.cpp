// #0867. Transpose Matrix
// https://leetcode.com/problems/transpose-matrix/

#include<bits/stdc++.h>
using namespace std;


// Runtime: 14 ms, faster than 69.83% of C++ online submissions for Transpose Matrix.
// Memory Usage: 10.6 MB, less than 78.16% of C++ online submissions for Transpose Matrix.

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size() ,vector<int> (matrix.size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
