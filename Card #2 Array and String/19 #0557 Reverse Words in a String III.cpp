// LeetCode Arrays & Strings - 19
// #0557 Reverse Words in a String III

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            if(s[i] == ' ' || i == s.size() -1){
                if(temp != "" && temp != " "){
                    reverse(temp.begin(),temp.end());
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        
        temp = "";
        for(int i=0;i<words.size();i++){
            temp +=words[i];
            if(i!=words.size()-1){
                temp += " ";
            }
        }
        return temp;
    }
};