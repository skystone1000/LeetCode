// LeetCode Arrays & Strings - 10
// #0344 Reverse String    


class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // Method 1 (easiest)
        // reverse(s.begin(),s.end());
        
        // Method 2
        int n = s.size();
        for(int i=0;i<n/2;i++){
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
};