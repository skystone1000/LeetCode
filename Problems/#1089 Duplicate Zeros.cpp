// LeetCode arrays 4
// #1089 Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

#include<bits/stdc++.h>
using namespace std;

// Method 3 (Time - O(n), Space - O(1)) - two pass
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0;
        int temp = 0;
        bool edgeZero = false;
        
        // Finding new End point
        while(temp<arr.size()){
            if(arr[i] == 0){
                i++;
                if(temp == arr.size()-1){
                    edgeZero = true;
                    temp++;
                }else{
                    temp += 2;
                }
            } else {
                i++;
                temp++;
            }
        }
        
        // Hadling Edge case if only one zero at end
        i--;temp--;
        if(edgeZero == true){
            arr[temp] = arr[i];
            temp--;
            i--;
        }
        
        // Updating elements
        while(i>=0){
            if(arr[i] == 0){
                arr[temp] = 0;
                arr[temp-1] = 0;
                temp -= 2;
                i--;
            }else{
                arr[temp] = arr[i];
                i--;temp--;
            }
        }
        
    }
};

// Method 2 (Creating new array)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(ans.size() == arr.size())
                break;
            if(arr[i] == 0){
                ans.push_back(0);
                ans.push_back(0);
            } else {
                ans.push_back(arr[i]);
            }
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i] = ans[i];
        }
    }
};

// Method 1 (TLE)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                arr.insert( arr.begin() + i , 0 );
            }
        }
    }
};