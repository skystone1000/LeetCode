// April Challenge 2021 - Day 17
// #1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

/*
REF - 
Number of Submatrices That Sum to Target | DP | 1074 LeetCode | LeetCode Explore | Day 17
    https://www.youtube.com/watch?v=x21lPXfkJqw
    
1074. Number of Submatrices That Sum to Target (Company Freq, Explanation)
    http://leetcode.libaoj.in/number-of-submatrices-that-sum-to-target.html

Subarray sum equals K | Number of subarrays with sum equals K | Leetcode #560​
    https://www.youtube.com/watch?v=HbbYPQc-Oo4

*/

class Solution {
public:

    // TIME COMPLEXITY:- O(N*M^2)
    // SPACE COMPLEXITY:- O(N*M)
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        
        // store prefix sum for each row
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                mat[i][j]+=mat[i][j-1];
        }
        
        int ans = 0;
        // map to store prefix sum of rows for a particular range of columns
        unordered_map<int,int> mp;
        
        for(int start=0;start<m;start++){
            for(int end=start;end<m;end++){
                // we are considering columns b/w {start,end}
                // clear previous entries
                mp.clear();
                mp[0]++;
                int sum = 0;
                // add sum for each row b/w the given range of columns
                for(int i=0;i<n;i++){
                    // add sum for this row b/w {start,end}
                    // curr stores sum of current row of matrix b/w given range of columns
                    int curr = mat[i][end];
                    if(start>0)
                        curr-=mat[i][start-1];
                    // sum of matrix elements upto now b/w given range
                    sum+=curr;
                    // increment answers
                    ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};


// Row Wise
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        int result = 0;
        for (int rb = 0; rb < n; ++rb) {
            for (int re = rb; re < n; ++re) {
                int sum = 0;
                unordered_map<int, int> counts;
                counts[0] = 1;
                for (int j = 0, s; j < m; ++j) {
                    if (rb == 0) {
                        s = matrix[re][j];
                    } else {
                        s = matrix[re][j] - matrix[rb - 1][j];
                    }
                    sum += s;
                    result += counts[sum - target];
                    ++counts[sum];
                }
            }
        }
        return result;
    }
};