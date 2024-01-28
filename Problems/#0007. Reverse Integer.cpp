// #0007. Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Pop and Push Digits & Check before Overflow
// Time Complexity: O(log(x)). There are roughly log10​(x) digits in x
// Space Complexity: O(1)
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }
            rev = (rev * 10) + digit;
            x = x / 10;
        }
        return rev;
    }
};

// Check if condition is redundent
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // Check if condition is redundent
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};