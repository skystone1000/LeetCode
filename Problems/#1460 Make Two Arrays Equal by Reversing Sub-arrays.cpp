// Search array 10
// #1460 Make Two Arrays Equal by Reversing Sub-arrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i=0;i<target.size();i++){
            freq[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int flag = 0;
        for(pair elem:freq){
            // cout<<elem.first<<" "<<elem.second<<endl;
            if(elem.second % 2 == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            return false;
        }else{
            return true;
        }
        
    }
};

class Solution2 {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001,0);
        for(int i=0;i<target.size();i++){
            freq[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]--;
        }
        int flag = 0;
        for(int i=0;i<1001;i++){
            if(freq[i]<0){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            return false;
        }else{
            return true;
        }
        
    }
};