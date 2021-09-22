// Company Amazon
// 46 #1046. Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() <= 0)
            return 0;
        priority_queue<int> maxHeap;
        for(int i=0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            // cout<<x<<" "<<y<<endl;
            if(x==y)
                continue;
            else
                maxHeap.push(x-y);
            
        }

        if(maxHeap.size() == 1)
            return maxHeap.top();
        else 
            return 0;

    }
};