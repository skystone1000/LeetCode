// #1529 Bulb Switcher IV

class Solution {
public:
    int minFlips(string target) {
        int flips=0;
        for(int i=0;i<target.size();i++){
            
            if(i==0){
                if(target[i] == '1'){
                    flips++;
                    continue;                    
                }else
                    continue;
            }
            if(target[i] != target[i-1]){
                flips++;
            }
        }
        cout<<"Flips = "<<flips;
        return flips;
    }
};

