// Company Amazon
// AIE 4.2 #0134. Gas Station
// https://leetcode.com/problems/gas-station/


class Solution {
public:
    
    // Time - O(n)  Space O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, total_sum=0, current_sum=0;
        for(int i=0;i<gas.size();i++){
            int diff = gas[i] - cost[i];
            current_sum += diff;
            total_sum += diff;
            if(current_sum < 0){
                start = i+1;
                current_sum = 0;
            }
        }
        
        if(total_sum >=0)
            return start;
        
        return -1;
    }
    
    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int end = 1;
        int n = gas.size();
        int curr_petrol = gas[start] - cost[start];
        
        if(n==1){
            if(gas[0] >= cost[0])
                return 0;
            else 
                return -1;
        }
        
        while(end != start || curr_petrol < 0){
            while(curr_petrol < 0 && start != end){
                curr_petrol -= gas[start] - cost[start];
                start = (start+1) % n;
                
                if(start == 0)
                    return -1;
            }
            
            curr_petrol += gas[end] - cost[end];
            end = (end+1) % n;
        }
        
        return start;
    }*/
    
};