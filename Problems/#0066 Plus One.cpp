// LeetCode Arrays & Strings - 3
// #0066 Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        /*
        // Method 1 (Number very long) - Long Long overflow
        long long number=0;
        for(long long digit : digits){
            number = number * 10 + digit;
        }
        
        number++;
        cout<<"number = "<<number<<endl;
        
        vector<int> result;
        while(number > 0){
            int digit = number % 10;
            result.push_back(digit);
            number = number / 10;
        }
        
        reverse(result.begin(),result.end());
        
        return result;
        */
        
        // Method 2
        int i = digits.size() - 1;
        while(i>=0){
            if(i==0 && digits[i] == 9){
                digits[i] = 0;
                digits.insert(digits.begin(),1);
                break;
            }else if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i]++;
                break;
            }
            i--;
        }
        return digits;        
    }
};