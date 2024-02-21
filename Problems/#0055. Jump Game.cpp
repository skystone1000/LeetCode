// #0055. Jump Game
// https://leetcode.com/problems/jump-game/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Backtracking (Not Accepted: TLE)
// Time: O(2^n) , Space: O(n)
class Solution {
public:
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) {
            return true;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) { return canJumpFromPosition(0, nums); }
};


// Approach 2: Dynamic Programming Top-down
// Time: O(n^2) , Space: O(n)
enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    vector<Index> memo;
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (memo[position] != UNKNOWN) {
            return memo[position] == GOOD ? true : false;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = GOOD;
                return true;
            }
        }
        memo[position] = BAD;
        return false;
    }

    bool canJump(vector<int>& nums) {
        memo = vector<Index>(nums.size());
        for (int i = 0; i < memo.size(); i++) {
            memo[i] = UNKNOWN;
        }
        memo[memo.size() - 1] = GOOD;
        return canJumpFromPosition(0, nums);
    }
};


// Approach 3: Dynamic Programming Bottom-up
// Time: O(n^2) , Space: O(n)
enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKNOWN);
        memo[memo.size() - 1] = GOOD;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int furthestJump = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == GOOD) {
                    memo[i] = GOOD;
                    break;
                }
            }
        }
        return memo[0] == GOOD;
    }
};


// Approach 4: Greedy
// Time: O(n) , Space: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};