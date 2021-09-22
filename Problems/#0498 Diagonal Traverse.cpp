// LeetCode Arrays & Strings - 4
// #0498 Diagonal Traverse

// Time:  O(m * n)
// Space: O(m * n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        for (int r = 0; r < nums.size(); ++r) {
            for (int c = 0; c < nums[r].size(); ++c) {
                if (ans.size() <= r + c) {
                    ans.emplace_back();
                }
                ans[r + c].emplace_back(nums[r][c]);
            }
        }
        
        
        for (auto rp:ans) {
            for (auto cp:rp) {
                cout<<cp<<"  ";
            }cout<<endl;
        }
        
        vector<int> result;
        int count = 1;
        for (const auto& row: ans) {
            for (int i = 0; i <= row.size() - 1; ++i) {
                if(count % 2 == 0)
                    result.emplace_back(row[i]);
                else
                    result.emplace_back(row[row.size() - i - 1]);
            }
            count++;
        }
        return result;
    }
};
