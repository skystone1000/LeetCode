// Search array 01
// #1365 How Many Numbers Are Smaller Than the Current Number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>count(101,0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(int i=99;i>=0;i--){
            count[i]+=count[i+1];
        }
        
        int sum=0;
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            ans[i]=n-count[nums[i]];
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if (nums[i] > nums[j])
                    count++;
            }
            ans[i] = count;
        }
        for(auto &x:ans){
            cout<<x<<" "<<endl;;
        }
        return ans;
    }
};