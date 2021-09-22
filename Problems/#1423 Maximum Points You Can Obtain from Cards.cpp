// May Challenge 2021 - Day 11
// #1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        int window = 0;
        int left = 0;
        int right = n - k;
        
        // total = accumulate(cardPoints.begin(), cardPoints.end(), total);
        for(int i=0;i<cardPoints.size();i++)
            total += cardPoints[i];
        
        for(int i=0;i<right;i++)
            window += cardPoints[i];
        
        int ans = total - window;
        while(right < n){
            window -= cardPoints[left++];
            window += cardPoints[right++];
            
            ans = max(total - window, ans);
        }
        
        return ans;
    }
};