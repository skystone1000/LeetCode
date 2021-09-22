// April Challenge 2021 - Day 12
// #0667. Beautiful Arrangement II

// Method 2 (dividing into 2 lists)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int c = 0;
        for (int v = 1; v < n-k; v++) {
            ans[c] = v;
            c++;
        }
        for (int i = 0; i <= k; i++) {
            
            if(i%2 == 0)
                ans[c] = n-k + i/2;
            else
                ans[c] = n - i/2;
            
            c++;
        }
        return ans;
    }
};

// Method 3 ()
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int top = 1;
        int bot = n;
        
        vector<int> ans;
        while(top<=bot){
            if(k%2 == 1){
                ans.push_back(top); 
                top++;
            }else{
                ans.push_back(bot);
                bot--;
            }
            
            if(k>1)
                k--;
        }
        
        return ans;
    }
};