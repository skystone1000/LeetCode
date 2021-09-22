// Company Amazon
// AIE 9.6 #0384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/

class Solution {
    vector<int> nums,shuff;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        shuff = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return shuff = nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // Fisher Yates
        int i = shuff.size()-1;
        while( i > 0 ){
            int j = rand() % (i+1);
            swap(shuff[i], shuff[j]);
            i--;
        }
        
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */