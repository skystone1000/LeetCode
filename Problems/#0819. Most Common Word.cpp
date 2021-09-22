// Company Amazon
// 16 #0819. Most Common Word
// https://leetcode.com/problems/most-common-word/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if(paragraph.size() == NULL)
            return "";
        
        unordered_map <string, int> wordFreq;
        unordered_set <string> ban;
        
        for(string word:banned){
            ban.insert(word);
        }
        
        string curr = "";
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i] == '!' || paragraph[i] == '?' || paragraph[i] == '\'' ||
               paragraph[i] == ',' || paragraph[i] == ';' || paragraph[i] == '.' ||
               paragraph[i] == ' '){
                transform(curr.begin(), curr.end(), curr.begin(), ::tolower);
                if(ban.count(curr) > 0 || curr.size() == 0){
                    curr = "";
                    continue;
                } else{
                    wordFreq[curr]++;
                    curr = "";
                }
            } else {
                curr += paragraph[i];
            }
        }
        
        // this is used for last word check
        transform(curr.begin(), curr.end(), curr.begin(), ::tolower);
        if(ban.count(curr) > 0 || curr.size() == 0){
        } else{
            wordFreq[curr]++;
        }
        
        
        
        int maxCount = 0;
        string word = "";
        
        for(auto ele:wordFreq){
            // cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.second > maxCount){
                maxCount = ele.second;
                word = ele.first;
            }
        }
        
        return word;
    }
};