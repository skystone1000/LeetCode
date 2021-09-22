// June Challange Day 25
// 25 #0389 Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(auto i : s+t){
            ans^=i;
        }
        return ans;
    }
};

/*
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        // t will be 1 digit greater
        for(int i=0;i<s.size();i++){
            if(s[i] == t[i]){
                continue;
            }else{
                return t[i];
            }
        }
        
        // Handling case when the extra char is at last position
        return t[t.size()-1];
    }
};
*/

/*
// Not working - Failing when multiple same digits
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        for(char inT:t){
            int flag = 0;
            for(char inS:s){
                if(inS == inT){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return inT;
        }
        return 'a';
    }
};
*/