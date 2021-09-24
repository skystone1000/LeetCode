// LeetCode arrays 10
// #1299 Replace Elements with Greatest Element on Right Side  

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int max = 0;
            for(int j=i+1;j<arr.size();j++){
                if(max < arr[j]){
                    max = arr[j];
                }
            }
            arr[i] = max;
            if(i == arr.size()-1){
                arr[i] = -1;
            }
        }
        return arr;
    }
};