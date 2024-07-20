// #1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 5: Binary Search Using DFS
// Time Complexity : O(m⋅n), Space Complexity: O(m⋅n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (dfsUtil(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfsUtil(vector<vector<int>> &heights, int mid) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        return canReachDestinaton(0, 0, heights, visited, row, col, mid);
    }

    bool canReachDestinaton(int x, int y, vector<vector<int>> &heights,
                            vector<vector<bool>> &visited, int row, int col,
                            int mid) {
        if (x == row - 1 && y == col - 1) {
            return true;
        }
        visited[x][y] = true;
        for (auto direction : directions) {
            int adjacentX = x + direction[0];
            int adjacentY = y + direction[1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                !visited[adjacentX][adjacentY]) {
                int currentDifference =
                    abs(heights[adjacentX][adjacentY] - heights[x][y]);
                if (currentDifference <= mid) {
                    if (canReachDestinaton(adjacentX, adjacentY, heights,
                                           visited, row, col, mid))
                        return true;
                }
            }
        }
        return false;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};


// Approach 4: Binary Search Using BFS
// Time Complexity : O(m⋅n), Space Complexity: O(m⋅n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canReachDestinaton(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // use bfs to check if we can reach destination with max absolute difference
    // k
    bool canReachDestinaton(vector<vector<int>> &heights, int mid) {
        int row = heights.size();
        int col = heights[0].size();
        queue<Cell> queue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue.push(Cell(0, 0));
        visited[0][0] = true;
        while (!queue.empty()) {
            Cell curr = queue.front();
            queue.pop();
            if (curr.x == row - 1 && curr.y == col - 1) {
                return true;
            }
            for (auto direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) &&
                    !visited[adjacentX][adjacentY]) {
                    int currentDifference = abs(heights[adjacentX][adjacentY] -
                                                heights[curr.x][curr.y]);
                    if (currentDifference <= mid) {
                        visited[adjacentX][adjacentY] = true;
                        queue.push(Cell(adjacentX, adjacentY));
                    }
                }
            }
        }
        return false;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }

    class Cell {
    public:
        int x, y;
        Cell(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };
};



// Approach 3: Union Find - Disjoint Set
// Time Complexity : O(m⋅n(log(m⋅n))), Space Complexity : O(m⋅n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        if (row == 1 && col == 1) return 0;
        UnionFind unionFind(heights);
        vector<Edge> edgeList = unionFind.edgeList;
        sort(edgeList.begin(), edgeList.end(), compareInterval);

        for (int i = 0; i < edgeList.size(); i++) {
            int x = edgeList[i].x;
            int y = edgeList[i].y;
            unionFind.makeUnion(x, y);
            if (unionFind.find(0) == unionFind.find(row * col - 1))
                return edgeList[i].difference;
        }
        return -1;
    }

    class Edge {
    public:
        int x, y;
        int difference;

        Edge(int x, int y, int difference) {
            this->x = x;
            this->y = y;
            this->difference = difference;
        }
    };

    static bool compareInterval(const Edge& p1, const Edge& p2) {
        return (p1.difference < p2.difference);
    }

    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        vector<Edge> edgeList;

        UnionFind(vector<vector<int>>& heights) {
            int row = heights.size();
            int col = heights[0].size();
            parent.assign(row * col, 0);
            rank.assign(row * col, 0);
            for (int currentRow = 0; currentRow < row; currentRow++) {
                for (int currentCol = 0; currentCol < col; currentCol++) {
                    if (currentRow > 0) {
                        edgeList.push_back(
                            Edge(currentRow * col + currentCol,
                                 (currentRow - 1) * col + currentCol,
                                 abs(heights[currentRow][currentCol] -
                                     heights[currentRow - 1][currentCol])));
                    }
                    if (currentCol > 0) {
                        edgeList.push_back(
                            Edge(currentRow * col + currentCol,
                                 currentRow * col + currentCol - 1,
                                 abs(heights[currentRow][currentCol] -
                                     heights[currentRow][currentCol - 1])));
                    }
                    parent[currentRow * col + currentCol] =
                        currentRow * col + currentCol;
                }
            }
        }

        int find(int i) {
            if (parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        }

        void makeUnion(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);
            if (parentX != parentY) {
                if (rank[parentX] > rank[parentY])
                    parent[parentY] = parentX;
                else if (rank[parentX] < rank[parentY])
                    parent[parentX] = parentY;
                else {
                    parent[parentY] = parentX;
                    rank[parentX] += 1;
                }
            }
        }
    };
};



// Approach 2: Variations of Dijkstra's Algorithm
// Time Complexity : O(m⋅nlog(m⋅n)), Space Complexity: O(m⋅n)
class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>> &heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> differenceMatrix(row, vector<int>(col, INT_MAX));
        differenceMatrix[0][0] = 0;
        priority_queue<Cell, vector<Cell>, Comparator> queue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue.push(Cell(0, 0, differenceMatrix[0][0]));

        while (!queue.empty()) {
            Cell curr = queue.top();
            queue.pop();
            visited[curr.x][curr.y] = true;
            if (curr.x == row - 1 && curr.y == col - 1) 
                return curr.difference;

            for (auto direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) && !visited[adjacentX][adjacentY]) {
                    int currentDifference = abs(heights[adjacentX][adjacentY] - heights[curr.x][curr.y]);
                    int maxDifference = max(currentDifference, differenceMatrix[curr.x][curr.y]);
                    if (differenceMatrix[adjacentX][adjacentY] > maxDifference) {
                        differenceMatrix[adjacentX][adjacentY] = maxDifference;
                        queue.push(Cell(adjacentX, adjacentY, maxDifference));
                    }
                }
            }
        }
        return differenceMatrix[row - 1][col - 1];
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }

    class Cell {
    public:
        int x, y;
        int difference;
        Cell(int x, int y, int difference) {
            this->x = x;
            this->y = y;
            this->difference = difference;
        }
    };

    struct Comparator {
        bool operator()(Cell const &p1, Cell const &p2) {
            return p2.difference < p1.difference;
        }
    };
};



// Approach 1: Brute Force using Backtracking
// Let m be the number of rows and n be the number of columns in the matrix heights.
// Time Complexity : O(3^(m⋅n)), Space Complexity: O(m⋅n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        return backtrack(0, 0, heights, heights.size(), heights[0].size(), 0);
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxSoFar = INT_MAX;

    int backtrack(int x, int y, vector<vector<int>> &heights, int row, int col, int maxDifference) {
        if (x == row - 1 && y == col - 1) {
            maxSoFar = min(maxSoFar, maxDifference);
            return maxDifference;
        }
        int currentHeight = heights[x][y];
        heights[x][y] = 0;
        int minEffort = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int adjacentX = x + directions[i][0];
            int adjacentY = y + directions[i][1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                heights[adjacentX][adjacentY] != 0) {
                int currentDifference = abs(heights[adjacentX][adjacentY] - currentHeight);
                int maxCurrentDifference = max(maxDifference, currentDifference);
                if (maxCurrentDifference < maxSoFar) {
                    int result = backtrack(adjacentX, adjacentY, heights, row, col, maxCurrentDifference);
                    minEffort = min(minEffort, result);
                }
            }
        }
        heights[x][y] = currentHeight;
        return minEffort;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};