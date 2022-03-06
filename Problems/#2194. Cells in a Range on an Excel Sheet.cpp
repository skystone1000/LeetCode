// 2194. Cells in a Range on an Excel Sheet
// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for(char i=s[0];i<=s[3];i++){
            for(char j=s[1];j<=s[4];j++){
                string str = {i, j};
                ans.push_back(str);
            }
        }
        return ans;
    }
};



// Attempt during contest
class Solution {
public:
    vector<string> cellsInRange(string s) {
        int flag=0;
        string c1,c2,rs1,rs2;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                if(flag == 1){
                    c2 = c2 + s[i];
                }else{
                    c1 = c1 + s[i];
                }
            }else if (s[i] >= '0' && s[i] <= '9'){
                if(flag == 1){
                    rs2 = rs2 + s[i];
                }else{
                    rs1 = rs1 + s[i];
                }
            }else if(s[i] == ':'){
                flag = 1;
            }
        }
        cout<<c1<<" "<<c2<<" "<<rs1<<" "<<rs2<<endl;
        
        vector<string> ans;
        char currChar1 = c1[0];
        char currChar2 = c2[0];
        while(currChar1<=currChar2){
            for(int j=stoi(rs1);j<=stoi(rs2);j++){
                ans.push_back(currChar1+to_string(j));
                // cout<<currChar1+to_string(j)<<" ";
            }
            currChar1++;
        }
        
        return ans;
    }
};