// 1446 Consecutive Characters
// https://leetcode.com/problems/consecutive-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0){
            return 0;
        }
        
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