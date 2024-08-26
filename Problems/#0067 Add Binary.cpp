// LeetCode Arrays & Strings - 7
// #0067 Add Binary
// https://leetcode.com/problems/add-binary/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Bit Manipulation
// Time complexity: O(N+M), where N and M are lengths of the input strings a and b.
// Space complexity: O(max(N,M))
class BigInt {
private:
    string binary;

    // Helper function to ensure strings are the same length
    static void equalizeLength(string& a, string& b) {
        int lengthDifference = a.size() - b.size();
        if (lengthDifference > 0)
            b.insert(0, lengthDifference, '0');
        else
            a.insert(0, -lengthDifference, '0');
    }

    // Helper function to remove leading zeros
    void removeLeadingZeros() {
        // Erase leading zeros while keeping at least one zero if the number is
        // zero
        auto firstNonZero = binary.find_first_not_of('0');
        if (firstNonZero != string::npos) {
            binary.erase(0, firstNonZero);
        } else {
            binary =
                "0";  // Adjust to maintain a minimum representation of zero
        }
    }

public:
    BigInt() : binary("0") {}

    // Constructor from a binary string
    BigInt(const string& bin) : binary(bin) { removeLeadingZeros(); }

    // Bitwise XOR
    BigInt operator^(const BigInt& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char xorChar = (a[i] == b[i] ? '0' : '1');
            result.push_back(xorChar);
        }
        return BigInt(result);
    }

    // Bitwise AND
    BigInt operator&(const BigInt& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char andChar = (a[i] == '1' && b[i] == '1' ? '1' : '0');
            result.push_back(andChar);
        }
        return BigInt(result);
    }

    // Left shift
    BigInt operator<<(int shift) const {
        string result = binary;
        result.append(shift, '0');
        return BigInt(result);
    }

    // Check if BigInt is zero
    bool isZero() const {
        for (char c : binary)
            if (c != '0') return false;
        return true;
    }

    // Getter for binary string
    string getBinary() const { return binary; }
};

class Solution {
public:
    string addBinary(string a, string b) {
        BigInt x(a);
        BigInt y(b);
        BigInt carry, answer;

        while (!y.isZero()) {
            answer = x ^ y;
            carry = (x & y) << 1;
            x = answer;
            y = carry;
        }
        return x.getBinary();
    }
};


// Approach 1: Bit-by-Bit Computation
// Time complexity: O(max(N,M))
// Space complexity: O(max(N,M))
class Solution {
public:
    /* 
    converting char to int
    char a = '4';
    int ia = a - '0';
     */
    
    string addBinary(string a, string b) {
        string ans;
        const int maxLen = max(a.size(),b.size());
        
        int carry = 0;
        for(int i=0;i<maxLen;i++){
            const int a_bit = i<a.size() ? a[a.size() - 1 - i] - '0' : 0 ;
            const int b_bit = i<b.size() ? b[b.size() - 1 - i] - '0': 0 ;
            int sum = carry + a_bit + b_bit;
            carry = sum/2;
            sum = sum % 2;
            ans.push_back('0' + sum);
        }        
        if(carry){
            ans.push_back('0' + carry);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Approach 0 : In built methods
// O(N+M) time complexity
class Solution {
public:
    string addBinary(string a, string b) {
        int numA = stoi(a, nullptr, 2);  // Convert binary string to integer
        int numB = stoi(b, nullptr, 2);  // Convert binary string to integer
        int sum = numA + numB;           // Sum the integers
        if (sum == 0) return "0";
        string binary =
            bitset<32>(sum).to_string();  // Convert sum to binary string
        return binary.substr(binary.find('1'));
    }
};