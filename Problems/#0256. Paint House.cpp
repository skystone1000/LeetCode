// #0256. Paint House
// https://leetcode.com/problems/paint-house/description/
// Company Tag - Amazon, google

#include<bits/stdc++.h>
using namespace std;


// Read Five -> Approach 4: Dynamic Programming (In place)
// Time Complexity : O(n), Space Complexity : O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        for (int n = costs.size() - 2; n >= 0; n--) {
            // Total cost of painting the nth house red.
            costs[n][0] += min(costs[n + 1][1], costs[n + 1][2]);
            // Total cost of painting the nth house green.
            costs[n][1] += min(costs[n + 1][0], costs[n + 1][2]);
            // Total cost of painting the nth house blue.
            costs[n][2] += min(costs[n + 1][0], costs[n + 1][1]);
        }

        return min(min(costs[0][0], costs[0][1]), costs[0][2]);
    }
};


// Read Four -> Approach 5: Dynamic Programming with Optimized Space Complexity
// Time Complexity : O(n), Space Complexity : O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;

        vector<int> previousRow = costs[costs.size() - 1];

        for (int n = costs.size() - 2; n >= 0; n--) {
            vector<int> currentRow = costs[n];
            // Total cost of painting the nth house red.
            currentRow[0] += min(previousRow[1], previousRow[2]);
            // Total cost of painting the nth house green.
            currentRow[1] += min(previousRow[0], previousRow[2]);
            // Total cost of painting the nth house blue.
            currentRow[2] += min(previousRow[0], previousRow[1]);
            previousRow = currentRow;
        }

        return min({previousRow[0], previousRow[1], previousRow[2]});
    }
};


// Read Three -> Approach 3: DP Bottom Up
// Time complexity : O(n), Space complexity : O(n).
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;

        vector<vector<int>> memo = {costs.size() + 1, vector<int>(3, 0)};

        for (int i = costs.size() - 1; i >= 0; --i) {
            memo[i][0] = costs[i][0] + min(memo[i + 1][1], memo[i + 1][2]);
            memo[i][1] = costs[i][1] + min(memo[i + 1][0], memo[i + 1][2]);
            memo[i][2] = costs[i][2] + min(memo[i + 1][0], memo[i + 1][1]);
        }

        return min(min(memo[0][0], memo[0][1]), memo[0][2]);
    }
};


// Read Two -> Approach 3: Memoization
// Time complexity : O(n), Space complexity : O(n).
class Solution {
private:
    vector<vector<int>> costs;
    unordered_map<string, int> memo;

public:
    int minCost(vector<vector<int>>& _costs) {
        if (_costs.size() == 0) {
            return 0;
        }
        this->costs = _costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

private:
    int paintCost(int n, int color) {
        string key = getKey(n, color);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        memo[key] = totalCost;

        return totalCost;
    }

    string getKey(int n, int color) {
        return to_string(n) + " " + to_string(color);
    }
};


// Read one -> Approach 2: Brute force with a Recursive Tree (TLE)
// Time complexity : O(2^n), Space complexity : O(n).
class Solution {
public:
    vector<vector<int>> costs;
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
            return 0;
        }
        this->costs = costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

    int paintCost(int n, int color) {
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        return totalCost;
    }
};