// #0844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach #2: Two Pointer
// Time Complexity: O(M+N), where M,N are the lengths of S and T
// Space Complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return updateString(s) == updateString(t);
    }

    string updateString(string currStr){
        int counter = 0;
        for(int i=0;i<currStr.size();i++){
            if(currStr[i] == '#'){
                if(counter > 0)
                    counter--;
            }else{
                currStr[counter] = currStr[i];
                counter++;
            }
        }
        return currStr.substr(0,counter);
    }
};

// Approach #1: Build String 
// Time Complexity: O(M+N), where M,N are the lengths of S and T
// Space Complexity: O(M+N)
class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            return build(S) == build(T);
        }
        
        string build(const string& str) {
            stack<char> st;
            for (char c : str) {
                if (c != '#') {
                    st.push(c);
                } else if (!st.empty()) {
                    st.pop();
                }
            }
    
            // Convert stack to string
            string result;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
    
            // Reverse since stack gives characters in reverse order
            reverse(result.begin(), result.end());
            return result;
        }
    };