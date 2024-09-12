// #0779. K-th Symbol in Grammar
// https://leetcode.com/problems/k-th-symbol-in-grammar/

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Recursion
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    int kthGrammar(int N, int K) {
        // Base Condition
        if(N==1 && K==1)
            return 0;

        // Hypothesis
        int mid = pow(2, N-1) / 2;

        // Induction
        if( K <= mid){
            return kthGrammar(N-1, K);
        } else {
            return !kthGrammar(N-1, K-mid);
        }
    }
};