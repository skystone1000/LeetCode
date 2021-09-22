// LeetCode Arrays & Strings - 2
// #0747 Largest Number At Least Twice of Others 

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=0, max2=0,index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]> max){
                max2 = max;
                max = nums[i];
                index = i;
            }
            else{
                if(nums[i] > max2){
                    max2 = nums[i];
                }
            }
        }
        
        cout<<"Max= "<<max<<endl;
        cout<<"Max2= "<<max2<<endl;
        
        
        if(max >= 2*max2){
            return index;
        }else{
            return -1;
        }
        
    }
};