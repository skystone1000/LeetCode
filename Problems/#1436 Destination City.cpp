// 1436. Destination City

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans ;
        for(int i=0;i<paths.size();i++){
            string curr = paths[i][1];
            int flag = 0;
            cout<<curr;
            
            for(int j=0;j<paths.size();j++){
                 if(curr == paths[j][0]){
                     flag = 1;
                     break;
                 }
            }            
            if(flag == 1){
                continue;
            }else if(flag == 0){
                ans = curr;
                return ans;
            }
            
        }
        return ans;
        
    }
};
