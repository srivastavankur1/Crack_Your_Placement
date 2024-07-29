class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while(head != nullptr ){
            if(head ->next != nullptr && head->val==head->next->val){
                //skip the node that are equal
                while(head ->next != nullptr && head->val==head->next->val){
                    head= head->next;
                }
                prev->next = head->next;
            }
            else{
                prev = prev->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};