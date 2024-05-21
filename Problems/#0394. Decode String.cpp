// #0394. Decode String
// https://leetcode.com/problems/backspace-string-compare/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 3 - Recursion
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    string decodeString(const string& s, int& index) {
        string result;
        while (index < s.length() && s[index] != ']') {
            if (!isdigit(s[index]))
                result += s[index++];
            else {
                int k = 0;
                // build k while next character is a digit
                while (index < s.length() && isdigit(s[index]))
                    k = k * 10 + s[index++] - '0';  
                // ignore the opening bracket '['    
                index++;
                string decodedString = decodeString(s, index);
                // ignore the closing bracket ']'
                index++;        
                while (k-- > 0)
                    result += decodedString;
            }
        }
        return result;
    }
};

// Approach 2 - Two stack
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;
        for (auto ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.top(); currentK > 0; currentK--) {
                    decodedString = decodedString + currentString;
                }
                countStack.pop();
                currentString = decodedString;
            } else {
                currentString = currentString + ch;
            }
        }
        return currentString;
    }
};


// Approach 1 - One Stack solution
class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString = "";
                // get the encoded string
                while (stack.top() != '[') {
                    decodedString += stack.top();
                    stack.pop();
                }
                // pop [ from stack
                stack.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!stack.empty() && isdigit(stack.top())) {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                int currentLen = decodedString.size();
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString[j]);
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s[i]);
            }
        }
        // get the result from stack
        string result;
        for (int i = stack.size() - 1; i >= 0; i--) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};
