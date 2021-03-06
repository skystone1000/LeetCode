// LeetCode arrays 9
// #0941 Valid Mountain Array  
// https://leetcode.com/problems/valid-mountain-array/submissions/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Two pointer start, end
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        while (i + 1 < n && A[i] < A[i + 1]) 
            i++;
        while (j > 0 && A[j - 1] > A[j]) 
            j--;
        
        if(i > 0 && i == j && j < n - 1)
            return true;
        return false;
    }
};

// Method 2
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;
        
        // Find max;
        int max = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            if(A[i] > max){
                max = A[i];
                index = i;
            }
        }
        
        // Check if only increasing or decreasing
        if(index == 0 || index == n-1)
            return false;
        
        // Check Increasing
        for(int i=1;i<=index;i++){
            if(A[i] > A[i-1])
                continue;
            else
                return false;
        }
        // Check Decreasing
        for(int i=index;i<n-1;i++){
            if(A[i] > A[i+1])
                continue;
            else
                return false;
        }
        return true;
        
    }
};