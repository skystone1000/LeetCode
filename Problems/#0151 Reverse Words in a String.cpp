// LeetCode Arrays & Strings - 18
// #0151 Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                temp = temp + s[i];
            }
            if(s[i] == ' ' || i == s.size()-1 ){
                // Cheking if we dont push empty of string with just space
                if(temp != "" && temp != " "){
                    words.push_back(temp);
                    temp = "";                    
                }
            }
        }
        
        temp = "";
        for(int i=words.size()-1 ;i>=0;i--){
            temp = temp + words[i];
            if(i != 0){
                temp += " ";
            }
        }
        return temp;
    }
};