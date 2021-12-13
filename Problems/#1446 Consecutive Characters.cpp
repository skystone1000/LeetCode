// 1446 Consecutive Characters
// https://leetcode.com/problems/consecutive-characters/

#include<bits/stdc++.h>
using namespace std;

// Method 3 - Sliding Window
// Time - O(N), Space - O(1)
class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        for(int i = 0; i < s.size(); ) {
            int j = i + 1;
            while(j < s.size() && s[j] == s[j-1])
                j++;
            power = max(power, j-i);
            // ensures we dont repeat iteration over same element again
            i = j;                             
        }
        return power;
    }
};

/*
// Method 2 - One pass solution
// Time - O(N), Space - O(1)
class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        int currMax = 1;
        for(int i=1;i<s.size();i++){
            if(s[i-1] == s[i]){
                currMax++;
            }
            
            // Not doing else so that we can get last iteration check
            // Sample input = "cc"
            if(s[i-1] != s[i] || i == s.size()-1){
                if(currMax > power)
                    power = currMax;
                currMax = 1;
            }
        }
        
        return power;
    }
};

// Method 1 - Brute force
// Time - O(N^2), Space - O(1)
class Solution {
public:
    int maxPower(string s) {
        int power = 0;
        for(int i = 0; i < s.size(); i++) {
            int j = i + 1;
            // Going till we have same character
            while(j < s.size() && s[j] == s[j-1])  
                j++;
            power = max(power, j-i);                  
        }
        return power;
    }
};
*/

// Method 2 Alternative
class Solution {
public:
    int maxPower(string s) {
        char lptr,rptr;
        lptr = s[0];
        int max=1,count = 1;
        for(int i=1;i<s.size();i++){
            if(lptr == s[i]){
                count++;
                continue;
            }else{
                if(count > max){
                    max = count;
                }
                count = 1;
                lptr = s[i];
            }
        }
        
        if(count > max){
            max = count;
        }
        cout<<max;
        return max;
        
        
    }
};