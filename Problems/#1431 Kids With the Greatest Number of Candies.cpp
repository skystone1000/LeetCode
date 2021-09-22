// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for(auto kid : candies){
            if (kid > max){
                max = kid;
            }
        }
        
        vector <bool> ans;
        
        for(auto val : candies){
            if(val + extraCandies >= max){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
        
    }
};
