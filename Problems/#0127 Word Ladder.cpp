// Company Amazon
// 07 #0127 Word Ladder
// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false; //  to Check if end word is present in the dictonary
        
        // Insert all words from dict in myset
        for(auto word: wordList){
            if(endWord.compare(word) == 0) 
                isPresent = true;
            myset.insert(word);  // Insert word in Dict
        }
        
        if(isPresent == false) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            depth += 1;
            int lsize = q.size();  // NUmber of elements at a level;
            while(lsize--){
                string curr = q.front();
                q.pop();
                
                //Check for all possible 1 depth words
                for(int i=0;i<curr.length();i++){ // For each index
                    string temp = curr;
                    for(char c='a';c<='z';c++){    // Try all possible chars
                        temp[i] = c;
                        if(curr.compare(temp) == 0)
                            continue;               // Skip the same word
                        if(temp.compare(endWord) == 0)
                            return depth+1;         // endWord Found
                        if(myset.find(temp) != myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return depth;
    }
};


/*
Check whats wrong


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false;
        
        for(auto ele:wordList){
            myset.insert(ele);
            if(ele == endWord)
                isPresent = true;
        }
        
        if(isPresent == false) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(q.size() != 0){
            depth += 1;
            int lsize = q.size();
            while(lsize > 0){
                lsize--;
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        temp[i] = c;
                        if(curr == temp)
                            continue;
                        if(temp == endWord)
                            return depth+1;
                        if(myset.find(temp) != myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return depth;
    }
};
*/