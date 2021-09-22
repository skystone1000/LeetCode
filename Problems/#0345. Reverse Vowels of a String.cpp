// Company Amazon
// 43 #0345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vow;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vow.push(s[i]);
            }
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vow.top();
                vow.pop();
            }
        }
        
        return s;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vow;
        vow.insert('a');vow.insert('A');
        vow.insert('e');vow.insert('E');
        vow.insert('i');vow.insert('I');
        vow.insert('o');vow.insert('O');
        vow.insert('u');vow.insert('U');
        
        int i = 0, j = s.size() - 1;
        while(i<j){
            while(i<j && !vow.count(s[i])){
                i++;
            }
            while(i<j && !vow.count(s[j])){
                j--;
            }
            
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};