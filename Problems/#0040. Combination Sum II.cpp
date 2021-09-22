// Company Amazon
// 32 #0040. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        sort(candidates.begin(),candidates.end());
        findCombinations(candidates, target, vector<int>(), 0, vec);
        return vec;
    }
    
    void findCombinations(vector<int> candidates, int target, vector<int> current, int index, vector<vector<int>> &vec){

        if(target == 0){
            vec.push_back(vector<int> (current));
            return ;
        }
        
        if(target < 0){
            return ;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i == index || candidates[i] != candidates[i-1]){
                current.push_back(candidates[i]);
                findCombinations(candidates, target-candidates[i], current, i+1, vec);
                current.pop_back();
            }
        }
    }
};