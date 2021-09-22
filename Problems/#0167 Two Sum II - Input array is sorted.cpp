// LeetCode Arrays & Strings - 12
// #0167 Two Sum II - Input array is sorted

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left != right){
            const auto sum = numbers[left] + numbers[right];
            if(sum > target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                return {left+1,right+1};
            }
        }
        return {0,0};
    }
};


// TLE
/*
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i=0;i<numbers.size();i++){
            int required = target - numbers[i];
            
            std::vector<int>::iterator it; 
            it = std::find (numbers.begin()+i+1, numbers.end(), required); 
            if (it != numbers.end()){
                ans.push_back(i+1);
                ans.push_back(it - numbers.begin() + 1 );
                break;
            } 
        }
        return ans;
    }
};
*/