// April Challenge 2021 - Day 16
// #1209. Remove All Adjacent Duplicates in String II
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Method 1 - Stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(char c : s) {
            if(st.empty() || st.back().first != c) {
                st.push_back({c,1});
            } else {
                st.back().second++;
                if(st.back().second == k ) 
                    st.pop_back();
            }
        }
        string result="";
        for(auto t : st) {
            result.append(t.second,t.first);
        }
        return result;
    }
};

/*
// Method 2 -  Two Pointer Approach
class Solution {
public:
    string removeDuplicates(string s, int k) {
       int low=0, high=1;  
        int cnt=1;
        while(low<high && high<s.size()) {
            if(s[low]==s[high]) {
                cnt++;     
                if(cnt==k) {
                    s.erase(low,k); 
                    if((low-k)>=0) {
                        low = low-k;
                        high = low+1;
                    } else {
                        low=0;
                        high=1;
                    }
                  cnt=1;  
                } else if((high-low)<k) {
                    high++;
                }
            } else {
                low++;
                high= low+1;
                cnt=1;
            }  
        }
        return s; 
    }
};
*/