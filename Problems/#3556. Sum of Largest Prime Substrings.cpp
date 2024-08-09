// #3556. Sum of Largest Prime Substrings
// https://leetcode.com/problems/sum-of-largest-prime-substrings/description/
// Topics - Hash Table, Math, String, Sorting, Number Theory

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        set<long long, greater<long long>> possibleValues;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                long long curr = stoll(s.substr(i, j - i + 1));
                if (checkPrime(curr)) {
                    possibleValues.insert(curr);
                }
            }
        }

        long long sum = 0;
        int count = 0;
        for (auto ele : possibleValues) {
            sum += ele;
            count++;
            if (count == 3) break;
        }

        return sum;
    }

    bool checkPrime(long long n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
