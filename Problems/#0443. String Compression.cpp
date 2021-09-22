// Company Amazon
// 54 #0443. String Compression
// https://leetcode.com/problems/string-compression/


class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;
        while(i<chars.size()){
            int j = i;
            while(j<chars.size() && chars[j] == chars[i]){
                j++;
            }
            
            chars[index] = chars[i];
            index++;
            if(j-i > 1){
                string count = to_string(j-i);
                for(char c: count){
                    chars[index] = c;
                    index++;
                }
            }
            i = j;
        }
        return index;
    }
};