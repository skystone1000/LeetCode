// Company Amazon
// AIE 10.2 #0150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                int ele2 = st.top(); st.pop();
                int ele1 = st.top(); st.pop();
                
                if(tokens[i] == "+"){
                    st.push(ele1 + ele2);
                }
                else if(tokens[i] == "-"){
                    st.push(ele1 - ele2);
                }
                if(tokens[i] == "*"){
                    st.push(ele1 * ele2);
                }
                if(tokens[i] == "/"){
                    st.push(ele1 / ele2);
                }
                
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        
        // cout<<st.size()<<endl;
        return st.top();
    }
};