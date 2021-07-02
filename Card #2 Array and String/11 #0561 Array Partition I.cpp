// LeetCode Arrays & Strings - 11
// #0561 Array Partition I  

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // we get max sum when we sort the elements and then pair 2 elements from the start to end 
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i = i+2){
            sum += nums[i];
        }
        return sum;
    }
};