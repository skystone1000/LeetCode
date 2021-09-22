// #0258 Add Digits

class Solution2 {
public:
    int addDigits(int num) {
        int temp = num;
        while(temp > 9 ){
            int sum = 0;
            num = temp;
            while(num>0){
                sum = sum + num %10;
                num = num/10;
            }
            temp=sum;
        }
        return temp;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        if(num%9 == 0)
            return 9;
        return num%9 ;
    }
};