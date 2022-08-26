// LeetCode Arrays & Strings - 1
// #0869. Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Counting digits
class Solution {
public:
    // Counts frequency of each digit in given number N
    vector<int> countDigits(int N){
        vector<int>digitsInN(10);
        while(N){
            int dig = N % 10;
            digitsInN[dig]++;
            N /= 10;
        }
        return digitsInN;
    }

    bool reorderedPowerOf2(int N) {
        // freq of digits in N
        vector<int> digitsInN = countDigits(N); 

        // powOf2 goes from 2^0 to 2^29 and each time freq 
        // of digits in powOf2 is compared with digitsInN
        int powOf2 = 1;
        for(int i = 0; i < 30; i++){
            // return true if both have same frequency of each digits
            if(digitsInN == countDigits(powOf2)) 
                return true;
            
            powOf2 <<= 1;
        }
        return false;
    }
};

// Method 2 - compare strings
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string stringN = to_string(n);
        sort(stringN.begin(), stringN.end());
        
        int powof2 = 1;
        for(int i=0;i<30;i++){
            string stringPow = to_string(powof2);
            sort(stringPow.begin(),stringPow.end());
            if(stringN == stringPow)
                return true;
            powof2 <<= 1;
        }
        return false;
    }
};