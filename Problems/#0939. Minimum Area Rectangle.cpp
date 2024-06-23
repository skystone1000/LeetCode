// #0939. Minimum Area Rectangle
// https://leetcode.com/problems/minimum-area-rectangle/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Count by Diagonal
// Time Complexity: O(N2), where N is the length of points.
// Space Complexity: O(N).
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> pointSet;
        const int BASE = 40001;
        // Store all points in a set using unique encoding: x * BASE + y
        for (const auto& point : points) {
            long long encoded = static_cast<long long>(point[0]) * BASE + point[1];
            pointSet.insert(encoded);
        }
        int ans = INT_MAX;
        // Try every pair of points
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // Check if they form a diagonal (not in the same row or column)
                if (x1 != x2 && y1 != y2) {
                    long long p1 = static_cast<long long>(x1) * BASE + y2;
                    long long p2 = static_cast<long long>(x2) * BASE + y1;

                    // Check if the other two points exist to form a rectangle
                    if (pointSet.count(p1) && pointSet.count(p2)) {
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        ans = min(ans, area);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Approach 1: Sort by Column
// Time Complexity: O(N^2), where N is the length of points.
// Space Complexity: O(N).
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> rows;
        // Group points by x-coordinate
        for (auto& point : points) {
            int x = point[0], y = point[1];
            rows[x].push_back(y);
        }
        int ans = INT_MAX;
        unordered_map<long long, int> lastx;
        // For each x-coordinate, process its sorted y-values
        for (auto& [x, yList] : rows) {
            sort(yList.begin(), yList.end());
            for (int i = 0; i < yList.size(); ++i) {
                for (int j = i + 1; j < yList.size(); ++j) {
                    int y1 = yList[i], y2 = yList[j];
                    // Unique key for a vertical pair of y-values
                    long long code = static_cast<long long>(40001) * y1 + y2;
                    if (lastx.count(code)) {
                        ans = min(ans, (x - lastx[code]) * (y2 - y1));
                    }
                    // Update last seen x-coordinate for this vertical pair
                    lastx[code] = x;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
    