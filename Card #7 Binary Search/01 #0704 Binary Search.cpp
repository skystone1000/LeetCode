// Binary Search
// 01 #0704 Binary Search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        
        while(left < right){
            // cout<<left<<" "<<mid<<" "<<right<<endl;
            if(nums[mid] < target){
                left = mid + 1;
                mid = (left + right) / 2;
            }else if(nums[mid] > target){
                right = mid - 1;
                mid = (left + right) / 2;
            }else{
                break;
            }
        }
        
        if(nums[mid] == target){
            return mid;
        }else{
            return -1;
        }
    }
};