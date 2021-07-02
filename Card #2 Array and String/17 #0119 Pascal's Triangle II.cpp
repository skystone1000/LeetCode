// LeetCode Arrays & Strings - 17
// #0119 Pascal's Triangle II  

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        for(int i=0;i<=rowIndex;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp.push_back(1);
                }else{
                    temp.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
                }
            }
            pascal.push_back(temp);
        }
        return pascal[rowIndex];
    }
};