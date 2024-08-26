// LeetCode Arrays & Strings - 3
// #0066 Plus One
// https://leetcode.com/problems/plus-one/description/

#include<bits/stdc++.h>
using namespace std;

// Method 3 - Iterative
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> ans;
            int carry = 0; 
            for(int i=digits.size()-1;i>=0;i--){
                int curr = 0;
                if(i == digits.size()-1)
                    curr = digits[i] + carry + 1;
                else
                    curr = digits[i] + carry;
                carry = curr / 10;
                ans.push_back(curr%10); 
            }
    
            if(carry == 1){
                ans.push_back(1);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };

// Method 2 Recursive
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() == 9){
            digits.pop_back();
            digits = plusOne(digits);
            digits.push_back(0);
        }
        
        else if (digits.empty())
            digits.push_back(1);

        else
            digits.back()++;
        
        return digits;
    }
};


// Method 1 - Iterative with digit handling
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int i = digits.size() - 1;
            while(i>=0){
                if(i==0 && digits[i] == 9){
                    digits[i] = 0;
                    digits.insert(digits.begin(),1);
                    break;
                }else if(digits[i] == 9){
                    digits[i] = 0;
                }else{
                    digits[i]++;
                    break;
                }
                i--;
            }
            return digits;        
        }
    };