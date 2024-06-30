// #0994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Breadth-First Search (BFS)
// Time Complexity: O(NM), Space Complexity: O(NM)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Enqueue all rotten oranges and count fresh ones
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        // Edge case: no fresh oranges
        if (fresh == 0) return 0;

        // Sentinel to track time levels
        q.push({-1, -1});
        int minutes = -1;
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

        // Step 2: BFS
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();

            if (row == -1) {
                // To determine we have reached the end of level (Add a differentiator)
                // another way to achieve this is to put another for loop for size of queue
                minutes++;
                if (!q.empty()) q.push({-1, -1});
            } else {
                for (auto& d : directions) {
                    int nr = row + d[0], nc = col + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};


// Approach 2: In-place BFS
// Time Complexity: O((MN)^2), Space Complexity: O(1)

class Solution {
public:
    bool runRottingProcess(int timestamp, vector<vector<int>>& grid, int ROWS, int COLS) {
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        bool changed = false;

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == timestamp) {
                    for (auto& d : directions) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1) {
                            grid[nr][nc] = timestamp + 1;
                            changed = true;
                        }
                    }
                }
            }
        }

        return changed;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int timestamp = 2;

        while (runRottingProcess(timestamp, grid, ROWS, COLS)) {
            timestamp++;
        }

        for (auto& row : grid)
            for (int cell : row)
                if (cell == 1) return -1;

        return timestamp - 2;
    }
};