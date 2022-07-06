// LeetCode arrays 8
// #1346 Check If N and Its Double Exist    
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Brute Force
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(i==j) continue;
                if(arr[i] == 2*arr[j] || arr[j] == 2*arr[i])
                    return true;
            }
        }
        return false;
    }
};

// Method 2 - Hashset
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> check;
        for(int ele:arr){
            if(check.count(2*ele) > 0 || (ele%2==0 && check.count(ele/2) > 0 ))
                return true;
            check.insert(ele);
        }
        return false;
    }
};

// Method - Alternative for method 1
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