// Binary Search
// 08 #0034 Search for a Range

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start,end;
        int left = 0,right = nums.size() - 1;

        vector<int> ans;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                int temp = mid;
                // cout<<"found at :"<<mid<<endl;
                while(mid > 0 && nums[mid-1] == target){
                    mid--;
                }
                // cout<<"Start :"<<mid<<endl;
                start = mid;
                while(temp < nums.size()-1 && nums[temp+1] == target){
                    temp++;
                }
                // cout<<"End :"<<mid<<endl;
                end = temp;
                
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};