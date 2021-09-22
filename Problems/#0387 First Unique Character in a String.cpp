// Company Amazon
// 01 #0387 First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        // Method 1
        // Get each letter and search if that letter exists in remaining 
        // array, if not present return current element
        // Time : O(n2)
        
        // Method 2
        // Create a frequency map and iterate twice to find unique element
        // unordered_map<char,int> freq;
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]]++;
        // }
        // int i=0;
        // for(int i=0;i<s.size();i++){
        //     if(freq[s[i]] == 1){
        //         return i;
        //     }
        // }
        // return -1;
        
        // Method 3
        // Use a vector to store all 26 alphabets freq and iterate string to check first unique
        vector<int> freq(26,0);
        
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            if(freq[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};