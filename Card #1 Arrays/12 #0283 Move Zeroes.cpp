// LeetCode arrays 12
// #0283 Move Zeroes    

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
            }
        }
        
        nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
        
        for(int i=0;i<zeroCount;i++){
            nums.push_back(0);
        }
    }
};