// June Challenge 2021 - Day 29 - #1004. Max Consecutive Ones III
// #1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int end=0,start=0;
        
        for(end = 0 ; end < A.size() ; end++){
            if(A[end] == 0)
                K--;
            if(K < 0){
                if(A[start] == 0)
                    K++;
                start++;
            }
        }
        
        return end - start;
    }
};