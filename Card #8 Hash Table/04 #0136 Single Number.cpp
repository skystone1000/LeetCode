// Hash Table
// 04 #0136 Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        for(auto ele:freq){
            cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.second != 2){
                return ele.first;
            }
        }
        return -1;
    }
};
*/