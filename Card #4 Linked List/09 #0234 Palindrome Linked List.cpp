// Linked List 09
// 09 #0234 Palindrome Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        vector<int> start;
        ListNode* iter = head;
        while(iter != NULL){            
            start.push_back(iter->val);
            iter = iter -> next;
        }
        int p1 = 0,p2 = start.size()-1;
        int flag = 0;
        for(auto x:start){
            cout<<x<<" ";
        }
        cout<<endl;
        while(p1<=p2){
            if(start[p1] != start[p2]){
                flag = 1;
                break;
            }
            p1++;
            p2--;
        }
        if(flag == 1){
            return false;
        }else{
            return true;
        }
    }
};