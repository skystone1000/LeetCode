// Company Amazon
// AIE 6.6 #0045. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int count = 0;
        int i=0;
        while(i+nums[i] < nums.size() - 1){
            int maxVal = 0;
            int maxValIndex = 0;
            for(int j=1; j<=nums[i]; j++){
                if(nums[j+i]+j > maxVal){
                    maxVal = nums[j+i]+j;
                    maxValIndex = i+j;
                }
            }
            i = maxValIndex;
            count++;
        }
        return count+1;
    }
};