// Company Amazon
// AIE 6.4 #0239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        //using multiset for collecting the window data (O(nlog(k) time complexity)
        deque<int> q;
        for(int i=0; i<nums.size(); i++) {
            //remove the left item which leaves window 
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            //remove all num which less than current number from the back one by one
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            //insert the right itme which enter the window
            q.push_back(i);
            if (i>=k-1) {
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};