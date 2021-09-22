// Company Amazon
// 48 #0415. Add Strings
// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0){
                sum += num1[i] - '0';
                i--;
            }
            
            if(j>=0){
                sum += num2[j] - '0';
                j--;
            }
            result += to_string(sum % 10);
            carry = sum / 10;
        }
        
        if(carry != 0){
            result += '1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};