// #0740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/description/
// Tags - Amazon, Google

#include<bits/stdc++.h>
using namespace std;

// Approch 5: Further Thoughts: The Best of Both Worlds (not for interview)
// Given N as the length of nums and k as the maximum element in nums
// Time complexity: O(N+min(k,N⋅log(N)))
// Space complexity: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int maxNumber = 0;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        int twoBack = 0;
        int oneBack = 0;
        int n = points.size();

        // Condition: if maxNumber is not too large, use array-based DP
        if (maxNumber < n + n * log2(n)) {
            vector<int> dp(maxNumber + 1, 0);
            dp[1] = points.count(1) ? points[1] : 0;

            for (int num = 2; num <= maxNumber; ++num) {
                int gain = points.count(num) ? points[num] : 0;
                dp[num] = max(dp[num - 1], dp[num - 2] + gain);
            }

            return dp[maxNumber];
        } else {
            // Otherwise, use sorted list of unique elements
            vector<int> elements;
            for (auto& p : points) {
                elements.push_back(p.first);
            }
            sort(elements.begin(), elements.end());

            oneBack = points[elements[0]];
            for (int i = 1; i < elements.size(); ++i) {
                int currentElement = elements[i];
                int temp = oneBack;

                if (currentElement == elements[i - 1] + 1) {
                    oneBack = max(oneBack, twoBack + points[currentElement]);
                } else {
                    oneBack += points[currentElement];
                }

                twoBack = temp;
            }

            return oneBack;
        }
    }
};


// Approach 4: Iterate Over Elements
// Time complexity: O(N⋅log(N)), Space complexity: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
        }

        // Extract the unique keys (elements) and sort them
        vector<int> elements;
        for (auto& pair : points) {
            elements.push_back(pair.first);
        }
        sort(elements.begin(), elements.end());

        // Base cases
        int twoBack = 0;
        int oneBack = points[elements[0]];

        for (int i = 1; i < elements.size(); ++i) {
            int currentElement = elements[i];
            int temp = oneBack;
            if (currentElement == elements[i - 1] + 1) {
                // Adjacent elements: apply recurrence
                oneBack = max(oneBack, twoBack + points[currentElement]);
            } else {
                // Not adjacent: can safely take current element
                oneBack += points[currentElement];
            }
            twoBack = temp;
        }
        return oneBack;
    }
};




// Approach 3: Space Optimized Bottom-Up Dynamic Programming
// Time complexity: O(N+k), Space complexity: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        unordered_map<int, int> points;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        // Base cases
        int twoBack = 0;
        int oneBack = points.count(1) ? points[1] : 0;

        for (int num = 2; num <= maxNumber; ++num) {
            int temp = oneBack;
            int gain = points.count(num) ? points[num] : 0;
            oneBack = max(oneBack, twoBack + gain);
            twoBack = temp;
        }

        return oneBack;
    }
};


// Approach 2: Bottom-Up Dynamic Programming
// Time complexity: O(N+k), Space complexity: O(N+k)
class Solution {
private:
    unordered_map<int, int> points;
    unordered_map<int, int> cache;

public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        cache[0] = 0; 
        cache[1] = points[1];
        for(int i=2;i<=maxNumber;i++){
            cache[i] = max(cache[i-1], cache[i-2] + points[i]);
        }

        return cache[maxNumber];
    }
};

// With 2nd vector
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int maxNumber = 0;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        // Declare our array along with base cases
        vector<int> maxPoints(maxNumber + 1, 0);
        maxPoints[1] = points.count(1) ? points[1] : 0;

        for (int num = 2; num <= maxNumber; num++) {
            int gain = points.count(num) ? points[num] : 0;
            maxPoints[num] = max(maxPoints[num - 1], maxPoints[num - 2] + gain);
        }

        return maxPoints[maxNumber];
    }
};



// Approach 1: Top-Down Dynamic Programming
// Time complexity: O(N+k), Space complexity: O(N+k)
class Solution {
private:
    unordered_map<int, int> points;
    unordered_map<int, int> cache;

    int maxPoints(int num) {
        if (num == 0) return 0;
        if (num == 1) return points.count(1) ? points[1] : 0;
        
        if (cache.count(num) == 0) {
            cache[num] = max(maxPoints(num - 1), maxPoints(num - 2) + points[num]);
        }

        return cache[num];
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;

        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        return maxPoints(maxNumber);
    }
};