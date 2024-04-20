// #0247. Strobogrammatic Number II
// https://leetcode.com/problems/strobogrammatic-number-ii/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Iteration (Level Order Traversal)
// Time complexity: N⋅5^(⌊N/2⌋+1)
// Space complexity: O(N⋅5^⌊N/2⌋)
class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'}, 
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    vector<string> findStrobogrammatic(int n) {
        queue<string> q;
        int currStringsLength;
        
        // When n is even, it means when decreasing by 2 we will go till 0.
        if (n % 2 == 0) {
            // We will start with 0-digit strobogrammatic numbers.
            currStringsLength = 0;
            q.push("");
        } else {
            // We will start with 1-digit strobogrammatic numbers.
            currStringsLength = 1;
            q.push("0"); q.push("1"); q.push("8");
        }
        
        while (currStringsLength < n) {
            currStringsLength += 2;
            for (int i = q.size(); i > 0; --i) {
                string number = q.front();
                q.pop();
                
                for (vector<char>& pair : reversiblePairs) {
                    if (currStringsLength != n || pair[0] != '0') {
                        q.push(pair[0] + number + pair[1]);
                    }
                }
            }
        }

        vector<string> stroboNums;
        while (!q.empty()) {
            stroboNums.push_back(q.front());
            q.pop();
        }
        return stroboNums;
    }
};


// Approach 1: Recursion
// Time complexity: N⋅5^(⌊N/2⌋+1)
// Space complexity: O(N⋅5^⌊N/2⌋)

class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    vector<string> generateStroboNumbers(int n, int finalLength) {
        if (n == 0) {
            // 0-digit strobogrammatic number is an empty string.
            return { "" };
        }
        if (n == 1) {
            // 1-digit strobogrammatic numbers.
            return { "0", "1", "8" };
        }
        
        vector<string> prevStroboNums = generateStroboNumbers(n - 2, finalLength);
        vector<string> currStroboNums;
        for (string& prevStroboNum : prevStroboNums) {
            for (vector<char>& pair : reversiblePairs) {
                // We can only append 0's if it is not first digit.
                if (pair[0] != '0' || n != finalLength) {
                    currStroboNums.push_back(pair[0] + prevStroboNum + pair[1]);
                }
            }
        }
        return currStroboNums;
    }
    
    vector<string> findStrobogrammatic(int n) {
        return generateStroboNumbers(n, n);
    }
};
    