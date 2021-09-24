// LeetCode Queue & Stack 1
// #0622 Design Circular Queue 

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        cout<<"enque"<<endl;
        if(isFull() == true){
            return false;
        }
        if(isEmpty() == true){
            head++;
        }
        tail = (tail + 1) % size; 
        data[tail] = value;
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        cout<<"deque"<<endl;
        if(isEmpty() == true){
            return false;
        }
        if(head == tail){
            head = -1;
            tail = -1;
            return true;
        }else{
            head = (head+1) % size;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        cout<<"front"<<endl;
        if(isEmpty() == true ){
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        cout<<"rear"<<endl;

        if(isEmpty() == true ){
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(head ==-1){
            return true;
        }else{
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if( (tail+1)%size == head ){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */