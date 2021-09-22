// April Challenge 2021 - Day 25 - #0048. Rotate Image
// #0048. Rotate Image
// https://leetcode.com/problems/rotate-image/

// Time - O(N^2) = N is # of rows/cols , Space - O(1)
// Time - O(M) = M is # of elements in matrix
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        
        /*
        // Reverse with 2 pointers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j],matrix[i][n - j - 1]);
            }
        }
        */
        
        // Reverse with STL reverse
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Time - O(N^2) = N is # of rows/cols , Space - O(1)
// Time - O(M) = M is # of elements in matrix
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};