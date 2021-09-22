// Company Amazon
// 10 #0020 Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<int> pending;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                pending.push(s[i]);
                // cout<<"Push "<<s[i]<<endl;
            }
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(pending.size() < 1) return false;
                // cout<<"Pop "<<s[i]<<endl;
                char check;
                if(pending.top() == '(') check = ')';
                if(pending.top() == '{') check = '}';
                if(pending.top() == '[') check = ']';
                if(check == s[i]){
                    
                    pending.pop();
                }else{
                    return false;
                }
            }
        }
        if(pending.size() == 0)
            return true;
        else 
            return false;
    }
};