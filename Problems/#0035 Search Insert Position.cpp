// #0035 Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        // Method 1 (to find)        
        auto it = find(nums.begin(),nums.end(),target);
        if(it != nums.end()){
            return it - nums.begin();
        }*/
        
        // Method 2 if not present
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                return i;
            }else if(nums[i] > target){
                return i;
            }else{
                continue;
            }
        }
        return nums.size();
        
    }
};
