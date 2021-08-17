// Hash Table
// 06 #0202 Happy Number

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        
        while(n != 1 && !visited.count(n)){
            visited.emplace(n);
            
            int t = 0;
            while(n > 0){
                t += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = t;
            //cout<<n<<endl;
        }
        
        if(n==1)
            return true;
        else
            return false;
    }
};