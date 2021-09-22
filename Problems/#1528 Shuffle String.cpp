// #1528 Shuffle String

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<char> ans(n);
        
        for(int i=0;i<n;i++){
            ans[indices[i]] = s[i];
        }
        
        string result;
        for(auto &x:ans){
            result = result + x;
        }
        cout<<result;
        return result;
    }
};