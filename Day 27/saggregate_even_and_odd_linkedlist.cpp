Node* divide(Node* head) {
    if (!head) return nullptr; // If the list is empty

    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    Node* current = head;

    while (current) {
        if (current->data % 2 == 0) { // Current node is even
            if (!evenStart) { // Initialize the even list
                evenStart = current;
                evenEnd = evenStart;
            } else { // Add to the end of the even list
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        } else { // Current node is odd
            if (!oddStart) { // Initialize the odd list
                oddStart = current;
                oddEnd = oddStart;
            } else { // Add to the end of the odd list
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
        }
        current = current->next; // Move to the next node
    }

    // If there are no even nodes, return the odd list
    if (!evenStart) return oddStart;

    // If there are no odd nodes, return the even list
    if (!oddStart) return evenStart;

    // Combine even and odd lists
    evenEnd->next = oddStart;
    oddEnd->next = nullptr; // Ensure the end of the odd list points to null

    return evenStart;
}