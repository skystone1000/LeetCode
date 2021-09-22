// April Challenge 2021 - Day 21
// #0120. Triangle
// https://leetcode.com/problems/triangle/

// Time and apace => O(n^2) , O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> output(n,0);
        output[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(j==0)
                    output[j] = output[0] + triangle[i][j];
                else if(j==i)
                    output[j] = output[j-1] + triangle[i][j];
                else
                    output[j] = min(output[j],output[j-1]) + triangle[i][j];
            }
        }
        return *min_element(output.begin(),output.end());
    }
};

/*
// Time and space => O(n^2) , O(1) Changing the input 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int mn = INT_MAX;
                if(j<=i-1)
                    mn = min(mn,triangle[i-1][j]);
                if(j-1>=0)
                    mn = min(mn,triangle[i-1][j-1]);

                triangle[i][j] += mn;
            }
        }

        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};
*/