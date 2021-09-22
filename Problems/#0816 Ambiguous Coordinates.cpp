// May Challenge 2021 - Day 13
// #0816. Ambiguous Coordinates
// https://leetcode.com/problems/ambiguous-coordinates/


// Discussion : https://leetcode.com/problems/ambiguous-coordinates/discuss/123851/C%2B%2BJavaPython-Solution-with-Explanation

// Time complexity => O(N^3) with N <= 10
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i < n - 2; ++i) {
            vector<string> A = f(S.substr(1, i));
            vector<string> B = f(S.substr(i + 1, n - 2 - i));
            for (auto & a : A) 
                for (auto & b : B) 
                    res.push_back("(" + a + ", " + b + ")");
        }
        return res;
    }
    
    vector<string> f(string S) {
        int n = S.size();
        
        // Null String  ||  0xxx0
        if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0')) return {};
        
        // 0xxx9
        if (n > 1 && S[0] == '0') return {"0." + S.substr(1)};
        
        // single digit  ||  9xxx0
        if (n == 1 || S[n - 1] == '0') return {S};
        
        // 9xxx9
        vector<string> res = {S};
        for (int i = 1; i < n; ++i) 
            res.push_back(S.substr(0, i) + '.' + S.substr(i));
        return res;
    }
};