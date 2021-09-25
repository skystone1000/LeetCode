// Linked List 01
// #0707 Design Linked List    

struct Node
{
    int val;
    Node * next;
    Node(int x):val(x),next(NULL){};
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node*head;
    Node*tail;
    int size;
    MyLinkedList() {
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=this->size)
            return -1;
        Node *temp=this->head;
        int counter=0;
        while(temp){
            if(counter++==index)
                return temp->val;
            temp=temp->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *temp=new Node(val);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;
        }else{
            temp->next=this->head;
            this->head=temp;
        }
        this->size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp=new Node(val);
        if(this->tail==NULL){
            this->head=temp;
            this->tail=temp;
        }else{
            this->tail->next=temp;
            this->tail=temp;
        }
        this->size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>this->size)
            return;
        if(this->size==index){
            this->addAtTail(val);
            return;
        }
        if(index==0){
            this->addAtHead(val);
            return;
        }
        int count=0;
        Node* temp=this->head;
        while(temp){
            if(count++==index-1){
                Node * mid=new Node(val);
                mid->next=temp->next;
                temp->next=mid;
                break;
            }
            temp=temp->next;
        }
        this->size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size)
            return;
        if(index==0){
            this->head=this->head->next;
        }else if(index==size-1){
            int count=0;
            Node*temp=this->head;
            for(int i=0;i<index-1;i++)
                temp=temp->next;
            temp->next=temp->next->next;
            this->tail=temp;
        }else{
            int count=0;
            Node*temp=this->head;
            for(int i=0;i<index-1;i++)
                temp=temp->next;
            temp->next=temp->next->next;
        }
        this->size--;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */