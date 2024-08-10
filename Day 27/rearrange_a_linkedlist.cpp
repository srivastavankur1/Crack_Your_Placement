void rearrangeEvenOdd(Node *head) {
    if (!head || !head->next) return;  // If list is empty or has only one node

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;  // To connect odd list's end to even list's start

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    // Combine odd and even lists
    odd->next = evenHead;
}