// LeetCode Arrays & Strings - 14
// #0485 Max Consecutive Ones 

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max= 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
                continue;
            }else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
        }
        
        // Exit case with 1
        if(count > max){
            max = count;
        }
        return max;
        
    }
};