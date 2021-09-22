// LeetCode Arrays & Strings - 5
// #0054 Spiral Matrix

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