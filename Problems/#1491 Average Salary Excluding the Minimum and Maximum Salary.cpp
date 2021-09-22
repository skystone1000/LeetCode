// Search array 12
// #1491 Average Salary Excluding the Minimum and Maximum Salary

class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int least = salary[0];
        int greatest = salary[0];
        
        for(int i=0;i<salary.size();i++){
            if(salary[i] > greatest){
                greatest = salary[i];
            }
            if(salary[i] < least){
                least = salary[i];
            }
            
            sum += salary[i];
        }
        
        sum = sum - (least + greatest);
        double avg = sum / (salary.size() - 2);
        return avg;
    }
};