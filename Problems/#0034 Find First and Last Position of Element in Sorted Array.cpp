// April Challenge 2021 - Day 29
// #0034. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Method 3 - Binary search - O(logN)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int start = -1, end = -1;
        
        vector<int> ans;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                int temp = mid;
                
                while(mid > 0 && nums[mid-1] == target){
                    mid--;
                }
                start = mid;
                while(temp < nums.size()-1 && nums[temp+1] == target){
                    temp++;
                }
                end = temp;
                
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

/*
// Method 2 - Linear search - O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                    last = i;
                } else {
                    last = i;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
*/

/*
// Method 1 - Upper and Lower Bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        vector<int>::iterator it;
        it = std::find (nums.begin(), nums.end(), target);
        if (it == nums.end()){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        vector<int>::iterator lower, upper;
        lower = lower_bound(nums.begin(), nums.end(), target);
        upper = upper_bound(nums.begin(), nums.end(), target);
        ans.push_back(lower - nums.begin());
        ans.push_back(upper - nums.begin() - 1);
        
        return ans;
    }
};
*/