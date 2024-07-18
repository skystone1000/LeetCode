// #1335. Minimum Difficulty of a Job Schedule
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 4: Monotonic Stack - Better Time Complexity
// Time complexity: O(n⋅d), Space complexity: O(n)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }

        vector<int> minDiffPrevDay(n, 1000);
        vector<int> minDiffCurrDay(n, 0);
        vector<int> tmp;

        for (int day = 0; day < d; ++day) {
            stack<int> stk;
            for (int i = day; i < n; ++i) {
                // Initialize current day's value
                if (i > 0)
                    minDiffCurrDay[i] = minDiffPrevDay[i - 1] + jobDifficulty[i];
                else
                    minDiffCurrDay[i] = jobDifficulty[i];

                // Maintain a monotonic decreasing stack
                while (!stk.empty() && jobDifficulty[stk.top()] <= jobDifficulty[i]) {
                    int j = stk.top(); stk.pop();
                    int diffIncr = jobDifficulty[i] - jobDifficulty[j];
                    minDiffCurrDay[i] = min(minDiffCurrDay[i], minDiffCurrDay[j] + diffIncr);
                }

                if (!stk.empty()) {
                    minDiffCurrDay[i] = min(minDiffCurrDay[i], minDiffCurrDay[stk.top()]);
                }

                stk.push(i);
            }

            // Swap the arrays for next day
            tmp = minDiffPrevDay;
            minDiffPrevDay = minDiffCurrDay;
            minDiffCurrDay = tmp;
        }

        return minDiffPrevDay[n - 1];
    }
};



// Approach 3: Bottom-up 1D DP
// Time complexity: O(d⋅n^2), Space complexity: O(n)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; // Not enough jobs

        vector<int> minDiffNextDay(n + 1, INT_MAX);
        minDiffNextDay[n] = 0;  // Base case: no jobs left → difficulty 0

        for (int day = 1; day <= d; day++) {
            vector<int> minDiffCurrDay(n + 1, INT_MAX);

            for (int i = 0; i <= n - day; i++) {
                int hardest = 0;
                for (int j = i; j <= n - day; j++) {
                    hardest = max(hardest, jobDifficulty[j]);
                    if (minDiffNextDay[j + 1] != INT_MAX) {
                        minDiffCurrDay[i] = min(minDiffCurrDay[i], hardest + minDiffNextDay[j + 1]);
                    }
                }
            }

            minDiffNextDay = minDiffCurrDay;
        }

        return minDiffNextDay[0] == INT_MAX ? -1 : minDiffNextDay[0];
    }
};





// Approach 2: Bottom-up 2D DP
// Time complexity: O(d⋅n^2), Space complexity: O(n⋅d)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // If we cannot schedule at least one job per day, it's impossible
        if (n < d) return -1;

        // dp[i][day] = minimum difficulty to schedule jobs[i:] in (d - day + 1) days
        vector<vector<int>> dp(n, vector<int>(d + 1, INT_MAX));

        // Base case: on the last day, schedule all remaining jobs
        dp[n - 1][d] = jobDifficulty[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            dp[i][d] = max(dp[i + 1][d], jobDifficulty[i]);
        }

        // Fill dp table for earlier days
        for (int day = d - 1; day >= 1; --day) {
            for (int i = day - 1; i < n - (d - day); ++i) {
                int hardest = 0;
                for (int j = i; j < n - (d - day); ++j) {
                    hardest = max(hardest, jobDifficulty[j]);
                    if (dp[j + 1][day + 1] != INT_MAX) {
                        dp[i][day] = min(dp[i][day], hardest + dp[j + 1][day + 1]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};


// Approach 1: Top-down DP
// Time complexity: O((n^2)⋅d), Space complexity: O(n⋅d)
class Solution {
private:
    int n, d;
    vector<vector<int>> memo;
    vector<int> jobDifficulty;
    vector<int> hardestJobRemaining;

    int dp(int i, int day) {
        // Base case: it's the last day, schedule all remaining jobs
        if (day == d) {
            return hardestJobRemaining[i];
        }

        if (memo[i][day] != -1) {
            return memo[i][day];
        }

        int best = INT_MAX;
        int hardest = 0;

        // Try assigning jobs from index i to j on this day
        // Leave at least (d - day) jobs for the remaining days
        for (int j = i; j < n - (d - day); ++j) {
            hardest = max(hardest, jobDifficulty[j]);
            best = min(best, hardest + dp(j + 1, day + 1));
        }

        memo[i][day] = best;
        return best;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();

        if (n < d) {
            return -1;
        }

        this->jobDifficulty = jobDifficulty;
        this->d = d;

        // Precompute the hardest job from i to end
        hardestJobRemaining.resize(n);
        int hardest = 0;
        for (int i = n - 1; i >= 0; --i) {
            hardest = max(hardest, jobDifficulty[i]);
            hardestJobRemaining[i] = hardest;
        }

        // Initialize memo with -1
        memo.assign(n, vector<int>(d + 1, -1));

        return dp(0, 1);
    }
};