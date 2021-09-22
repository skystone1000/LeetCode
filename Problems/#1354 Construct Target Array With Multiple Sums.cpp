// May Challenge 2021 - Day 9
// #1354. Construct Target Array With Multiple Sums
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(size(target) == 1) 
            return target[0] == 1;

        long sum=0;
        for(int i=0;i<target.size();i++)
            sum += target[i];

        priority_queue<int> pq(begin(target), end(target));

        // Repeat till all elements haven't been made equal to 1
        while(pq.top() != 1) {  

            long largest = pq.top(); pq.pop();
            long largest_2 = pq.top();
            long restArrSum = sum - largest;

            // n = number of subtraction to get largest below 2nd largest element. 
            // max(1, ..) denotes teh case where largest and largest_2 are equal
            int n = max(1l, (largest - largest_2) / restArrSum);

            // subtracting from largest n times
            largest -= (restArrSum * n); 

            // push element back & update the sum of array
            pq.push(largest);            
            sum = restArrSum + largest;

            // if an element gets below 1, we cant achieve original array
            if(largest < 1) return false;
        }
        return true;
    }
};