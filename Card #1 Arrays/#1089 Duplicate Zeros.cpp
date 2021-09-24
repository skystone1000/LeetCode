// LeetCode arrays 4
// #1089 Duplicate Zeros


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        /*
        // Method 1 (TLE)
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                arr.insert( arr.begin() + i , 0 );
            }
        }*/
        
        // Method 2
        vector<int> newArr;
        newArr.reserve(arr.size());
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                newArr.push_back(0);
            }
            newArr.push_back(arr[i]);
        }
        
        arr.reserve(newArr.size());
        for(int i=0;i<newArr.size();i++){
            arr[i] = newArr[i];
        }
    }
};