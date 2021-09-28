// Binary Search
// 06 #0162 Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[mid+1]){
                left = mid+1;
            }else {
                right = mid;
            }
        }
        return right;
    }
};

// input: [1,2]

/* // NOT WORKING CHECK BOUNDS
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        for(int i=1; i<nums.size() - 1;i++){
            if(i == 1){
                if(nums[i] < nums[i-1])
                    return i;
            }else if(i == nums.size() - 2){
                if(nums[i] < nums[i-1])
                    return i;
            }
            
            if(nums[i-1] < nums[i] && nums[i+1] < nums[i]){
                return i;
            }
        }
        return -1;
    }
};

// input: [1,2]
*/