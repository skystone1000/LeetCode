// 1437 Check If All 1's Are at Least Length K Places Away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int flag = 0;
        int currDist = 0;
        
        // Required for first 1 whose currDist = 0
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                currDist++;
            }else if(nums[i] == 1){
                if(currDist < k ){
                    if(count == 0){
                        count++;
                        continue;
                    }else{
                        flag = 1;
                        break;
                    }
                }else{
                    currDist = 0;
                }
            }
        }
        if(flag == 0){
            return true;
        }else {
            return false;
        }
    }
};