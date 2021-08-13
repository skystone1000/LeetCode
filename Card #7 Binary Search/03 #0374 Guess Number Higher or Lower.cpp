// Binary Search
// 03 #0374 Guess Number Higher or Lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        
        while(l<=r){
            int mid = l + (r-l) / 2;
            int res = guess(mid);
            if(res == 0){
                return mid;
            }else if(res == -1){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};