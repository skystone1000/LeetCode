// LeetCode arrays 3
// #0977 Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

// Method 0 - Time O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        int back = nums.size()-1;
        int front = 0;
        int revItr = nums.size()-1;
        
        while(front <= back){
            if(llabs(nums[front]) > llabs(nums[back])){
                ans[revItr] = nums[front] * nums[front];
                front++;
                revItr--;
            }else{
                ans[revItr] = nums[back] * nums[back];
                back--;
                revItr--;
            }
        }
        return ans;
    }
};


// Method 1 - Time O(N) - Space O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> st;
        int back = nums.size()-1, front = 0;
        
        while(front <= back){
            // cout<<front<<" "<<back<<endl;
            if(llabs(nums[front]) > llabs(nums[back])){
                st.push(nums[front] * nums[front]);
                front++;
            }else{
                st.push(nums[back] * nums[back]);                
                back--;
            }
            // cout<<st.top()<<endl;
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// Method 2 - Time O(NlogN) 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};