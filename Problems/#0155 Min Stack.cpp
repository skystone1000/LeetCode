// LeetCode Queue & Stack 5
// #0155 Min Stack

class MinStack {
private:
    vector<int> data;    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
    }
    
    void pop() {
        int size = data.size();
        if(size == 0){
            return;
        }
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        int min = data[0];
        for(int i=0;i<data.size();i++){
            if(min > data[i]){
                min = data[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */