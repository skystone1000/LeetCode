// Search array 13
// #922 Sort Array By Parity II

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<n;i++){
            if(A[i] % 2 == 0){
                even.push_back(A[i]);
            }else{
                odd.push_back(A[i]);
            }
        }
        int slow = 0;
        for(int i=0;i<n;i= i+2){
            A[i] = even[slow];
            A[i+1] = odd[slow];
            slow++;
        }
        return A;
    }
};