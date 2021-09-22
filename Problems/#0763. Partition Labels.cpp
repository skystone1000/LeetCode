// Company Amazon
// 34 #0763. Partition Labels
// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> partitionLengths;
        vector<int> last(26);
        for(int i=0;i<S.size();i++){
            last[S[i] - 'a'] = i;
        }
        
        int i=0;
        while(i<S.size()){
            int end = last[S[i] - 'a'];
            int j = i;
            while(j != end){
                end = max(end, last[S[j] - 'a']);
                j++;
            }
            
            partitionLengths.push_back(j - i + 1);
            i = j + 1;
        }
        
        return partitionLengths;
    }
};