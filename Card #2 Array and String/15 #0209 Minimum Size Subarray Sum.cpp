// LeetCode Arrays & Strings - 15
// #0209 Minimum Size Subarray Sum   

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = -1, sum = 0, min_size = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_size = min(min_size, i - start);
                sum -= nums[++start];
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};


// TLE
/*
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ansLen = 999999;
        vector<int> ans;
        
        sort(nums.rbegin(),nums.rend(),)
        
        for(int i=0;i<nums.size();i++){
            vector<int> tempVec;
            int tempSum = 0;
                
            for(int j=i;j<nums.size();j++){
                if(tempSum < s){
                    tempSum += nums[j];
                    tempVec.push_back(nums[j]);
                }
                if(tempSum >= s || j == nums.size()){
                    if(tempVec.size()<ansLen){
                        ans.clear();
                        ans = tempVec;
                        ansLen = tempVec.size();
                    }
                    break;
                }
            }
        }
        
        return ans.size();
    }
};
*/