// #1342. Number of Steps to Reduce a Number to Zero
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/


// Basic Iterative/Intuitive Approach
// Time Complexity : O(logN)
// Space Complexity : O(1)

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num != 0){
            if(num % 2 == 0)
                num /= 2;
            else 
                num -= 1;
            count++;
        }
        return count;
    }
};


// Recursive Approach
// Time Complexity : O(logN)
// Space Complexity : O(1)

class Solution {
public:
    int numberOfSteps(int num) { // number of steps to reach 0
        if(num==0) return 0; // base case 1 
        if(num==1) return 1; // base case 2
        return numberOfSteps(num/2)+(num%2==0?1:2); // recursive case and add 1 if num is odd else add 2
    }
};


// Bit-Manipulation Approach
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
int numberOfSteps(int num) { //  number of steps to reach 0    
        int count = 0; // number of steps 
        while(num){ // while n is not 0
            num = num & 1 ? num - 1 : num >> 1; // if n is odd, subtract 1, else right shift by 1
            count++; // increment count
        }
        return count; // return count
    }
};


// Builtin Functions
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int numberOfSteps(int num) { // number of steps to reach 0
        return num == 0 ? 0 : sizeof(num) * 8 - __builtin_clz(num) + __builtin_popcount(num) - 1; 
        // if num is 0, return 0 directly else length of num * 8 - number of leading zeros + number of 1s - 1
    }
};
