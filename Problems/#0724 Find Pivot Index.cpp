// LeetCode Arrays & Strings - 1
// #0724 Find Pivot Index  

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> start;
        vector<int> end;
        int startSum=0,endSum=0;
        
        for(int i=0;i<nums.size();i++){
            startSum += nums[i];
            start.push_back(startSum);
            endSum += nums[nums.size()-i-1];
            end.push_back(endSum);
        }
        
        reverse(end.begin(),end.end());
        
        /*
        for(int element : start){
            cout<<element<<" ";
        }
        cout<<endl;
        for(int element : end){
            cout<<element<<" ";
        }
        */
        
        int pivot = -1;
        for(int i=0;i<nums.size();i++){
            if(start[i] == end[i]){
                pivot = i;
                break;
            }
        }
        return pivot;
    }
};