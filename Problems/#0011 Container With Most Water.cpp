// Company Amazon
// 13 #0011 Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

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