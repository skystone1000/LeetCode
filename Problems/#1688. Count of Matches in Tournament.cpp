// #1688. Count of Matches in Tournament
// https://leetcode.com/problems/count-of-matches-in-tournament/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Simulation
class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n != 1){
            if(n%2 == 0){
                matches += n/2;
                n = n/2;
            }else{
                matches += (n-1)/2;
                n = ((n-1)/2) + 1;
            }
        }

        return matches;
    }
};


// Method 2 - Logic
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};