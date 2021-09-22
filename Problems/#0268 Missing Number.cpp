// Company Amazon
// 05 #0268 Missing Number
// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Method 1
        // Hashset solution
        // Time - O(n)  Space - O(n)
        /*
        set<int> myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        
        int loopCount = 0;
        for(int ele:myset){
            if(ele != loopCount){
                return loopCount;
            }
            loopCount++;
        }
        return nums.size();
        */
        
        // Method 2
        // Bit Manipulation
        // Time - O(n) Space - O(1)
        /*
        int temp = nums.size();
        for(int i=0;i<nums.size();i++){
            temp = temp ^ nums[i] ^ i;
        }
        return temp;
        */
        
        // Method 3 
        // Gauss' Formula
        // Time - O(n) Space - O(1)
        int n = nums.size();
        int sum = (n+1) * n / 2;
        
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
        }
        return sum-currSum;
    }
};