// #1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
// Company Tag - Google, Meta

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Breadth-first Search (BFS), Overwriting Input
// Time complexity : O(N), Space complexity : O(N)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        // All 8 possible directions
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Use grid itself to store distances

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            int distance = grid[row][col];

            // Reached target cell
            if (row == n - 1 && col == n - 1) {
                return distance;
            }

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0) {
                    
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = distance + 1;
                }
            }
        }

        return -1;  // Target unreachable
    }
};


// Approach 2: Breadth-first Search (Without Overwriting the Input)
// Time complexity : O(N), Space complexity : O(N)
// a) Distances on Queue
class Solution {
public:
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        queue<array<int, 3>> q; // row, col, distance
        q.push({0, 0, 1});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();
            if (row == n - 1 && col == n - 1) return dist;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n 
                    || grid[newRow][newCol] != 0 || visited[newRow][newCol]) continue;

                visited[newRow][newCol] = true;
                q.push({newRow, newCol, dist + 1});
            }
        }

        return -1;
    }
};

// b) New Collection for Each Distance (Two Queues)
class Solution {
public:
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        vector<pair<int, int>> currentLayer = {{0, 0}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        int currentDistance = 1;

        while (!currentLayer.empty()) {
            vector<pair<int, int>> nextLayer;
            for (auto [row, col] : currentLayer) {
                if (row == n - 1 && col == n - 1) return currentDistance;

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n 
                        || grid[newRow][newCol] != 0 || visited[newRow][newCol]) continue;

                    visited[newRow][newCol] = true;
                    nextLayer.emplace_back(newRow, newCol);
                }
            }
            currentLayer = move(nextLayer);
            currentDistance++;
        }

        return -1;
    }
};

// c) Track Number of Cells at Each Distance Using Queue Size
class Solution {
public:
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        int currentDistance = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [row, col] = q.front();
                q.pop();

                if (row == n - 1 && col == n - 1) return currentDistance;

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n 
                        || grid[newRow][newCol] != 0 || visited[newRow][newCol]) continue;

                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            currentDistance++;
        }

        return -1;
    }
};



// Approach 3: A* (Advanced)
// Time complexity : O(NlogN), Space complexity : O(N)
class Solution {
public:
    struct Candidate {
        int row, col;
        int distanceSoFar;
        int totalEstimate;

        Candidate(int r, int c, int d, int t) 
            : row(r), col(c), distanceSoFar(d), totalEstimate(t) {}

        // Min-heap based on totalEstimate
        bool operator>(const Candidate& other) const {
            return totalEstimate > other.totalEstimate;
        }
    };

    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        priority_queue<Candidate, vector<Candidate>, greater<Candidate>> pq;
        pq.emplace(0, 0, 1, estimate(0, 0, n));

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty()) {
            Candidate best = pq.top();
            pq.pop();

            int row = best.row, col = best.col;

            if (row == n - 1 && col == n - 1)
                return best.distanceSoFar;

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (isValid(newRow, newCol, grid, visited)) {
                    int newDistance = best.distanceSoFar + 1;
                    int totalEstimate = newDistance + estimate(newRow, newCol, n);
                    pq.emplace(newRow, newCol, newDistance, totalEstimate);
                }
            }
        }

        return -1;
    }

private:
    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               grid[row][col] == 0 && !visited[row][col];
    }

    int estimate(int row, int col, int n) {
        return max(n - row - 1, n - col - 1);
    }
};