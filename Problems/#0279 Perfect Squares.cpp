// LeetCode Queue & Stack 4
// #0279 Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        static vector<int> num{0};
        while (num.size() <= n) {
            int squares = numeric_limits<int>::max();
            for (int i = 1; i * i <= num.size(); ++i) {
                squares = min(squares, num[num.size() - i * i] + 1);
            }
            num.emplace_back(squares);
        }
        return num[n];
    }
};