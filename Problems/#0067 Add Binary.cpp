// LeetCode Arrays & Strings - 7
// #0067 Add Binary

class Solution {
public:
    
    /* converting char to int
    char a = '4';
    int ia = a - '0';
    check here if ia is bounded by 0 and 9 */
    
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