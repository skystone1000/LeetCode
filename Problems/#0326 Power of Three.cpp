// April Challenge 2021 - Day 27 - #0326. Power of Three
// #0326. Power of Three
// https://leetcode.com/problems/power-of-three/

// Method 4 - Integer Limitations
// Time complexity : O(1)
// Space complexity : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
         return n > 0 && 1162261467 % n == 0; 
    }
};

/*
// Method 3 - Base Conversion
// Time complexity : O(log3​n)
// Space complexity : O(log3​n)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        // conversion to base 3
        string nbase3 = "";
        while(n) {
            nbase3 += to_string(n % 3); 
            n /= 3;
        }
        int i = 0;
        while(i < size(nbase3) - 1) {
            if(nbase3[i] != '0') 
                return false; 
            i++;
        }
        // check if starting digit is 1
        return nbase3[i] == '1';   
    }
};
*/

/*
// Method 2 - Recursive
// Time complexity : O(log3​n)
// Space complexity : O(log3​n)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 1) return n == 1;
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};
*/


/*
// Method 1 - Loop Iteration
// Time complexity : O(log3​n)
// Space complexity : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;
        
        while (n % 3 == 0)
            n /= 3;
        
        return n == 1;
    }
};
*/