// #1832. Check if the Sentence Is Pangram
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26,0);
        
        for(int i=0;i<sentence.size();i++){
            arr[sentence[i] - 'a']++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0)
                return false;
        }
        
        return true;
    }
};