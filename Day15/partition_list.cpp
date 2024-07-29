class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* higher = new ListNode(0);

        ListNode* l1=small;
        ListNode* l2 = higher;
        
        while(head != nullptr){
            if(head -> val <x){
                //small list
                l1->next= head;
                l1 = l1->next;
            }
            else{
                //higher list
                l2->next = head;
                l2 =l2->next;
            }
            head=head->next;
        }
        l2->next = nullptr;
        l1->next = higher->next;

        return small->next;
    }
};