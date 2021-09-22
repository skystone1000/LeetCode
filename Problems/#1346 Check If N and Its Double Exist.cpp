// LeetCode arrays 8
// #1346 Check If N and Its Double Exist    

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        int flag = 0;
        std::vector<int>::iterator it;
        
        for(int element:arr){
            
            // Handling case of zero
            if(element == 0){
                int count = 0;
                for(int check :arr){
                    if (check == 0){
                        count++;
                    } 
                }
                if(count > 1){
                    flag = 1;
                    break;
                }else
                    continue;
            } // 
            
            
            it = std::find(arr.begin(),arr.end(),element*2);
            if (it != arr.end()){
                flag = 1;
                break;
            }
            else
                continue;
        }
        
        if(flag == 1){
            return true;
        }else{
            return false;
        }
        
    }
};