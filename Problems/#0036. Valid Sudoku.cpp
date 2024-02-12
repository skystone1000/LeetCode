// #0036. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/description/

#include<bits/stdc++.h>
using namespace std;


// Editorial solutions
// Approach 3: Bitmasking
// Time complexity: O(N^2), Space complexity: O(N)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        // Use a binary number to record previous occurrence
        int rows[N] = {0};
        int cols[N] = {0};
        int boxes[N] = {0};
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);
                // Check the row
                if ((rows[r] & pos) > 0) {
                    return false;
                }
                rows[r] |= pos;
                // Check the column
                if ((cols[c] & pos) > 0) {
                    return false;
                }
                cols[c] |= pos;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) {
                    return false;
                }
                boxes[idx] |= pos;
            }
        }
        return true;
    }
};


// Approach 2: Array of Fixed Length
// Time complexity: O(N^2), Space complexity: O(N^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use vectors to record the status
        vector<vector<int>> rows(N, vector<int>(N, 0));
        vector<vector<int>> cols(N, vector<int>(N, 0));
        vector<vector<int>> boxes(N, vector<int>(N, 0));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int pos = board[r][c] - '1';
                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }
                rows[r][pos] = 1;
                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }
                cols[c][pos] = 1;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }
                boxes[idx][pos] = 1;
            }
        }
        return true;
    }
};


// Approach 1: Hash Set
// Let N be the board length, which is 9 in this question
// Time complexity: O(N^2), Space complexity: O(N^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use hash set to record the status
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                // Check if the position is filled with number
                if (val == '.'){
                    continue;
                }

                int idx = (r / 3) * 3 + c / 3;
                if (
                    rows[r].find(val) != rows[r].end() ||       // Row
                    cols[c].find(val) != cols[c].end() ||       // Col
                    boxes[idx].find(val) != boxes[idx].end()    // Box
                )
                    return false;
                
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[idx].insert(val);
            }
        }
        return true;
    }
};