// 1446 Consecutive Characters

class Solution {
public:
    int maxPower(string s) {
        char lptr,rptr;
        lptr = s[0];
        int max=1,count = 1;
        for(int i=1;i<s.size();i++){
            if(lptr == s[i]){
                count++;
                continue;
            }else{
                if(count > max){
                    max = count;
                }
                count = 1;
                lptr = s[i];
            }
        }
        
        if(count > max){
            max = count;
        }
        cout<<max;
        return max;
        
        
    }
};