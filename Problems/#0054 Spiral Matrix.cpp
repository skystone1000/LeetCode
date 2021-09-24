// LeetCode Arrays & Strings - 5
// Company Amazon
// AIE 10.9
// #0054 Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        
        int count = 0, x=0,y=0;                
        int l = 0, d = matrix.size() - 1, u = 0, r = matrix[0].size() - 1;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        while (count<m*n || d>0 || r>0){
            cout<<endl<<"RIGHT"<<endl;
            for(int i=l;i<=r;i++){
                cout<<matrix[x][i]<<" ";
                ans.push_back(matrix[x][i]);
                count++;
                if(count >= m*n ) return ans;
            }
            y=r; u++;
            
            cout<<endl<<"DOWN"<<endl;
            for(int i=u;i<=d;i++){
                cout<<matrix[i][y]<<" ";
                ans.push_back(matrix[i][y]);
                count++;
                if(count >= m*n ) return ans;
            }
            x=d; r--;
            
            cout<<endl<<"LEFT"<<endl;
            for(int i=r;i>=l;i--){
                cout<<matrix[x][i]<<" ";
                ans.push_back(matrix[x][i]);
                count++;
                if(count >= m*n ) return ans;
            }
            y=l; d--;
            
            cout<<endl<<"UP"<<endl;
            for(int i=d;i>=u;i--){
                cout<<matrix[i][y]<<" ";
                ans.push_back(matrix[i][y]);
                count++;
                if(count >= m*n ) return ans;
            }
            x=u; l++;
        }
        return ans;
        
    }
};

class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row = matrix.size();
        if(row <= 0) return v;
        int col = matrix[0].size();
        if(col <= 0) return v;
        
        int r,c;
        for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        //top
        for(int i=c; i<col-c; i++){
            v.push_back(matrix[r][i]);
        }
        //right
        for(int i=r+1; i<row-r; i++){
            v.push_back(matrix[i][col-c-1]);
        }
        //bottom
        for(int i=col-c-2; row-r-1>r && i>=c; i--){
            v.push_back(matrix[row-r-1][i]);
        }
        //left
        for(int i=row-r-2; col-c-1>c && i>r; i--){
            v.push_back(matrix[i][c]);
        }
        
    }
    return v;
    }
};