// #1716. Calculate Money in Leetcode Bank
// 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalMoney(int n){
        int weeks = n / 7;
        int daysRem = n % 7;
        int weekSum = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        int total = 0;
        // weeks
        for (int i = 0; i < weeks; i++){
            total = total + weekSum + (i * 7);
        }

        // days rem
        for (int i = 0; i < daysRem; i++){
            total = total + (weeks + 1) + i;
        }

        return total;
    }
};