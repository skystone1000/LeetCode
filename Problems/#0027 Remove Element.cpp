// LeetCode arrays 6
// #0027 Remove Element
// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Method 0
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Method 1
        /*
        int count = 0;
        for(int i:nums){
            if(i != val){
                nums[count] = i;
                count++;
            }
        }
        return count;
        */
        
        
        // Method 2 - Remove unnecessary copy
        int n = nums.size();
        int i = 0;
        while(i<n) {
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }else {
                i++;
            }
        }
        return n;
        
    }
};