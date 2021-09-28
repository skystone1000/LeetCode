// Hash Table
// 05 #0349 Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> se1,se2;
        for(int i=0;i<nums1.size();i++){
            se1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            se2.insert(nums2[i]);
        }
        
        map<int,int> freq;
        for(int ele:se1){
            freq[ele]++;
        }
        for(int ele:se2){
            freq[ele]++;
        }
        
        vector<int> ans;
        for(auto ele:freq){
            if(ele.second == 2){
                ans.push_back(ele.first);
            }
        }
        
        return ans;
    }
};