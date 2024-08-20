// #0011 Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Company Tag - 13 Amazon

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Brute Force
// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int left = 0; left < height.size(); left++) {
            for (int right = left + 1; right < height.size(); right++) {
                int width = right - left;
                maxarea = max(maxarea, min(height[left], height[right]) * width);
            }
        }
        return maxarea;
    }
};


// Approach 2: Two Pointer Approach
// Time complexity: O(n), Space complexity: O(1)
/*
    The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line.
    Further, the farther the lines, the more will be the area obtained.

    We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. Further, we maintain 
    a variable maxarea to store the maximum area obtained till now. At every step, we find out the area formed between them, update maxarea, 
    and move the pointer pointing to the shorter line towards the other end by one step.

    The algorithm can be better understood by looking at the example below:
    1 8 6 2 5 4 8 3 7

    How does this approach work?
    Initially, we consider the area constituting the exterior most lines. Now, to maximize the area, we need to consider the area between the 
    lines of larger lengths. If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it is limited 
    by the shorter line. But moving the shorter line's pointer could turn out to be beneficial, as per the same argument, despite the reduction 
    in the width. This is done since a relatively longer line obtained by moving the shorter line's pointer might overcome the reduction in area 
    caused by the width reduction.

    Here is the proof.
    Proved by contradiction:
    Suppose the returned result is not the optimal solution. Then there must exist an optimal solution, say a container with a_ol and a_or 
    (left and right respectively), such that it has a greater volume than the one we got. Since our algorithm stops only if the two pointers meet. 
    So, we must have visited one of them but not the other. WLOG, let's say we visited a_ol but not a_or. When a pointer stops at a_ol, it won't move until
        1) The other pointer also points to a_ol.
        In this case, iteration ends. But the other pointer must have visited a_or on its way from right end to a_ol. 
        Contradiction to our assumption that we didn't visit a_or.
        2) The other pointer arrives at a value, say a_rr, that is greater than a_ol before it reaches a_or.
        In this case, we does move a_ol. But notice that the volume of a_ol and a_rr is already greater than a_ol and a_or 
        (as it is wider and heigher), which means that a_ol and a_or is not the optimal solution -- Contradiction!
    Both cases arrive at a contradiction.

    Yet another way to see what happens in the O(n) algorithm
    https://leetcode.com/problems/container-with-most-water/solutions/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm/
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            maxArea = max(maxArea, min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};



// Old Code
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Method 1 (Brute Force) - TLE
        // Time - O(n^2)  Space - O(1)
        /*
        int maxArea = 0;
        for(int i=0;i<height.size();i++){
            for(int j=0;j<height.size();j++){
                int minH = min(height[i],height[j]);
                int currArea = minH * (abs(i-j));
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
        */
        
        // Method 2 (Two Pointer Technique)
        // Time - O(n)  Space - O()
        int maxArea = 0, l = 0, r = height.size() - 1;
        while(l < r){
            int minH = min(height[l], height[r]);
            int currArea = minH * (r - l);
            maxArea = max(maxArea,currArea);
            
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};