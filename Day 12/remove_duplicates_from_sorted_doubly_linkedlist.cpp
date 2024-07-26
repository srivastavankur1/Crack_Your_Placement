class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    //non empty list
    ListNode* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL)&&curr->val == curr-> next-> val){
            ListNode* next_next = curr->next -> next;
            ListNode* nodetodelete = curr-> next;
            delete(nodetodelete);
            curr->next = next_next;

        }
        else{  //not equal
            curr = curr ->next;
        }
    }
    return head;        
    }
};