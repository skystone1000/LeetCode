// LeetCode arrays 2
// #1295 Find Numbers with Even Number of Digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount=0;
        for(int number:nums ){
            int digits = 0;
            while(number > 0){
                number = number / 10;
                digits++;
            }
            
            if(digits % 2 == 0){
                evenCount++;
            }
        }
        return evenCount;
    }
};