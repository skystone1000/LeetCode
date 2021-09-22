// Company Amazon
// 12 #0771 Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int>freq;
        for(char ele:S){
            freq[ele]++;
        }
        
        int count = 0;
        for(char ele:J){
            if(freq.count(ele) > 0){
                count += freq[ele];
            }
        }
        cout<<"Count = "<<count<<endl;
        return count;
    }
};