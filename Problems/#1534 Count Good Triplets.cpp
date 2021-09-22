// Search array 04
// #1534 Count Good Triplets

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count =0;
        for(int k=0;k<arr.size();k++){
            for(int j=0;j<k;j++){
                for(int i=0;i<j;i++){
                    if(
                        abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c
                      )
                        count++;
                }
            }
        }
        return count;
    }
};