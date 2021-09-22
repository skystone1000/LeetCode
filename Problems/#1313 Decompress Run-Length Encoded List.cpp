// Search array 02
// #1313 Decompress Run-Length Encoded List

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i=i+2){
            ans.resize(ans.size()+nums[i],nums[i+1]);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i=i+2){
            int freq = nums[i];
            int val = nums[i+1];
            for(int j=0;j<freq;j++){
                ans.push_back(val);
            }
        }
        return ans;
    }
};