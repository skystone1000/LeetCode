// Binary Search
// 04 #0033 Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] >= nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

/*
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        std::vector<int>::iterator it; 
        it = std::find (nums.begin(), nums.end(), target); 
        if (it != nums.end()) 
            return it - nums.begin(); 
        else
            return -1; 
    }
};

class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};
*/