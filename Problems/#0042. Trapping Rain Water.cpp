// #0042. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 4: Using 2 pointers
// Time complexity: O(n), Space complexity: O(1)
/*
    Neetcode Intuition
    At every point we move the pointers which ever is with lesser max till that point
    https://www.youtube.com/watch?v=ZI2z5pq0TqA
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int ans = 0;
        while (left < right) {
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
            }else{
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }
        return ans;
    }
};


/*
    Editorial solution

    Intuition
    As in Approach 2, instead of computing the left and right parts separately, we may think 
    of some way to do it in one iteration.

    From the figure in dynamic programming approach, notice that as long as 
    right_max[i]>left_max[i] (from element 0 to 6), the water trapped depends upon the left_max, 
    and similar is the case when left_max[i]>right_max[i] (from element 8 to 11).

    So, we can say that if there is a larger bar at one end (say right), we are assured that 
    the water trapped would be dependant on height of bar in current direction (from left to right).
    As soon as we find the bar at other end (right) is smaller, we start iterating in opposite 
    direction (from right to left).

    We must maintain left_max and right_max during the iteration, but now we can do it in 
    one iteration using 2 pointers, switching between the two.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += left_max - height[left];
                ++left;
            } else {
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += right_max - height[right];
                --right;
            }
        }
        return ans;
    }
};


// Approach 3: Using stacks
// Time complexity: O(n), Space complexity: O(n)
/*
    Intuition
    Instead of storing the largest bar upto an index as in Approach 2, we can use stack 
    to keep track of the bars that are bounded by longer bars and hence, may store water. 
    Using the stack, we can do the calculations in only one iteration.

    We keep a stack and iterate over the array. We add the index of the bar to the stack 
    if bar is smaller than or equal to the bar at top of stack, which means that the 
    current bar is bounded by the previous bar in the stack. If we found a bar longer 
    than that at the top, we are sure that the bar at the top of the stack is bounded by 
    the current bar and a previous bar in the stack, hence, we can pop it and add resulting 
    trapped water to ans.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = current - st.top() - 1;
                int bounded_height =
                    min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};


// Approach 2: Using Extra space for Max heights (Dp - but not exactly)
// Time complexity: O(n), Space complexity: O(n)
/*
    Intution
    In brute force, we iterate over the left and right parts again and again 
    just to find the highest bar size upto that index. But, this could be stored. 
    Voila, dynamic programming.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        int leftMaxTill = 0, rightMaxTill = 0;
        for(int i=0;i<n;i++){
            if(leftMaxTill < height[i])
                leftMaxTill = height[i];
            leftMax[i] = leftMaxTill;

            if(rightMaxTill < height[n-i-1])
                rightMaxTill = height[n-i-1];
            rightMax[n-i-1] = rightMaxTill;
        }

        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

// Editorial Solution
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

// Approach 1: Brute force
// Time complexity: O(n^2), Space complexity: O(1)
/*
    Intuition
    Do as directed in question. For each element in the array, we find the 
    maximum level of water it can trap after the rain, which is equal to the 
    minimum of maximum height of bars on both the sides minus its own height.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int leftMax = 0, rightMax = 0;
            // Search the left part for max bar size
            for (int j = i; j >= 0; j--) {
                leftMax = max(leftMax, height[j]);
            }
            // Search the right part for max bar size
            for (int j = i; j < size; j++) {
                rightMax = max(rightMax, height[j]);
            }
            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
};