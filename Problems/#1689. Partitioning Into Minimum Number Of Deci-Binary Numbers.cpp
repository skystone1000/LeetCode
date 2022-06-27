// #1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include<bits/stdc++.h>
using namespace std;

// Runtime: 30 ms, faster than 89.90% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
// Memory Usage: 13.6 MB, less than 65.18% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i=0;i<n.size();i++){
            if(n[i] - '0' > ans){
                ans = n[i] - '0';
                if(ans == 9) return ans;
            }
        }
        return ans;
    }
};
