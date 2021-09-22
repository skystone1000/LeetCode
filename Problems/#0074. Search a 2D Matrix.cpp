// Company Amazon
// AIE 4.6 #0074. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

// Time O(m+n) - Space O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size()){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target){
                j--;
            }else if(matrix[i][j] < target){
                i++;
            }
        }
        return false;
    }
};

// Time O(m*n) - Space O(1)
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        
        return false;
    }
};