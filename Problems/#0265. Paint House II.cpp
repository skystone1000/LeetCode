// #0265. Paint House II
// https://leetcode.com/problems/paint-house-ii/description/
// Company Tag - Amazon, google

#include<bits/stdc++.h>
using namespace std;


// Approach 5: Dynamic programming with Optimized Time and Space
// Time complexity : O(n⋅k), Space complexity : O(1)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        int n = costs.size();       // Number of houses
        int k = costs[0].size();    // Number of colors

        // Step 1: Initialize the first row's min and second min values
        int prevMin = -1, prevSecondMin = -1, prevMinColor = -1;
        for (int color = 0; color < k; ++color) {
            int cost = costs[0][color];
            if (prevMin == -1 || cost < prevMin) {
                prevSecondMin = prevMin;
                prevMinColor = color;
                prevMin = cost;
            } else if (prevSecondMin == -1 || cost < prevSecondMin) {
                prevSecondMin = cost;
            }
        }

        // Step 2: Process each house from 1 to n-1
        for (int house = 1; house < n; ++house) {
            int curMin = -1, curSecondMin = -1, curMinColor = -1;

            for (int color = 0; color < k; ++color) {
                int cost = costs[house][color];
                if (color == prevMinColor) {
                    cost += prevSecondMin;
                } else {
                    cost += prevMin;
                }

                // Update current min and second min
                if (curMin == -1 || cost < curMin) {
                    curSecondMin = curMin;
                    curMinColor = color;
                    curMin = cost;
                } else if (curSecondMin == -1 || cost < curSecondMin) {
                    curSecondMin = cost;
                }
            }

            // Carry over current min values to previous for next iteration
            prevMin = curMin;
            prevSecondMin = curSecondMin;
            prevMinColor = curMinColor;
        }

        return prevMin;
    }
};



// Approach 4: Dynamic programming with Optimized Time
// Time complexity : O(n⋅k), Space complexity : O(1)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        int n = costs.size();       // Number of houses
        int k = costs[0].size();    // Number of colors

        for (int house = 1; house < n; ++house) {
            int minColor = -1, secondMinColor = -1;

            // Step 1: Find min and second min cost from the previous row
            for (int color = 0; color < k; ++color) {
                int cost = costs[house - 1][color];

                if (minColor == -1 || cost < costs[house - 1][minColor]) {
                    secondMinColor = minColor;
                    minColor = color;
                } else if (secondMinColor == -1 || cost < costs[house - 1][secondMinColor]) {
                    secondMinColor = color;
                }
            }

            // Step 2: Compute new costs using min and second min
            for (int color = 0; color < k; ++color) {
                if (color == minColor) {
                    costs[house][color] += costs[house - 1][secondMinColor];
                } else {
                    costs[house][color] += costs[house - 1][minColor];
                }
            }
        }

        // Step 3: Find the minimum in the last row
        int result = *min_element(costs[n - 1].begin(), costs[n - 1].end());
        return result;
    }
};




// Approach 3: Dynamic Programming with O(k) additional Space.
// Time complexity : O(n⋅k^2), Space complexity : O(k)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        int n = costs.size();      // number of houses
        int k = costs[0].size();   // number of colors

        vector<int> previousRow = costs[0];

        for (int house = 1; house < n; ++house) {
            vector<int> currentRow(k, 0);

            for (int color = 0; color < k; ++color) {
                int minPrev = INT_MAX;

                for (int prevColor = 0; prevColor < k; ++prevColor) {
                    if (color == prevColor) continue;
                    minPrev = min(minPrev, previousRow[prevColor]);
                }

                currentRow[color] = costs[house][color] + minPrev;
            }

            previousRow = currentRow;
        }

        return *min_element(previousRow.begin(), previousRow.end());
    }
};



// Approach 2: Dynamic Programming(In place)
// Time complexity : O(n⋅k^2), Space complexity : O(1)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        int n = costs.size();        // Number of houses
        int k = costs[0].size();     // Number of colors

        for (int house = 1; house < n; ++house) {
            for (int color = 0; color < k; ++color) {
                int minCost = INT_MAX;

                for (int prevColor = 0; prevColor < k; ++prevColor) {
                    if (color == prevColor) continue;
                    minCost = min(minCost, costs[house - 1][prevColor]);
                }

                costs[house][color] += minCost;
            }
        }

        // Get minimum cost in the last row
        int finalMin = *min_element(costs[n - 1].begin(), costs[n - 1].end());
        return finalMin;
    }
};



// Approach 1: Memoization
// Time complexity : O(n⋅k^2), Space complexity : O(n⋅k)
class Solution {
    int n, k;
    vector<vector<int>> costs;
    unordered_map<string, int> memo;

    string getKey(int house, int color) {
        return to_string(house) + " " + to_string(color);
    }

    int memoSolve(int houseNumber, int color) {
        if (houseNumber == n - 1) {
            return costs[houseNumber][color];
        }

        string key = getKey(houseNumber, color);
        if (memo.count(key)) {
            return memo[key];
        }

        int minRemainingCost = INT_MAX;
        for (int nextColor = 0; nextColor < k; ++nextColor) {
            if (nextColor == color) continue;
            int currentRemainingCost = memoSolve(houseNumber + 1, nextColor);
            minRemainingCost = min(minRemainingCost, currentRemainingCost);
        }

        int totalCost = costs[houseNumber][color] + minRemainingCost;
        memo[key] = totalCost;
        return totalCost;
    }

public:
    int minCostII(vector<vector<int>>& inputCosts) {
        if (inputCosts.empty()) return 0;

        costs = inputCosts;
        n = costs.size();
        k = costs[0].size();
        memo.clear();

        int minCost = INT_MAX;
        for (int color = 0; color < k; ++color) {
            minCost = min(minCost, memoSolve(0, color));
        }

        return minCost;
    }
};