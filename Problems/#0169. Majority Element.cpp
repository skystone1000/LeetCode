// #0169. Majority Element
// https://leetcode.com/problems/majority-element/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 2 - Boyer-Moore Voting Algorithm
// Time - O(n) Space - O(1)
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 1;
            int candidate = nums[0];
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == candidate) {
                    count++;
                } else {
                    count--;
                }
    
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
    
            return candidate;
        }
    };
    