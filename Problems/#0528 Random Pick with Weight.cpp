// Leetcode
// #0528 Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight/

class Solution {
public:
    int n;
    vector<int> sumArr;   
    int sum =0;
    Solution(vector<int>& w) {
        sum=0;
        for(int i :w){
            sum +=i;
            sumArr.push_back(sum);
        }
        
    }
    
    int pickIndex() {
        int ans = rand() % sum ;
        return binarySearch(ans+1);
    }
    
    int binarySearch(int val){
        int l=0;
        int r=sumArr.size() -1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(sumArr[mid]<val)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */