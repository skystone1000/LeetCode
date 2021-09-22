// April Challenge 2021 - Day 9
// #0953 Verifying an Alien Dictionary


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alphabet(26);
        for(int i=0;i<order.size();i++){
            alphabet[order[i] - 'a'] = i;
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int minLen = min(words[i].size(), words[j].size());
                for(int k=0;k<minLen;k++){
                    char iChar = words[i][k];
                    char jChar = words[j][k];
                    
                    if(alphabet[iChar - 'a'] < alphabet[jChar - 'a']){
                        break;
                    } else if(alphabet[jChar - 'a'] < alphabet[iChar - 'a']){
                        return false;
                    } else if(k==minLen-1 && words[i].size() > words[j].size()){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};