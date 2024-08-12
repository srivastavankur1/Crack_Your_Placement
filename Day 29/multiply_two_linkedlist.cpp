#define MOD 1000000007
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1 = 0, num2 = 0;
        
        // Traverse the first list and form the number
        while (first != nullptr) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }
        
        // Traverse the second list and form the number
        while (second != nullptr) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }
        
        // Multiply the two numbers and return the result modulo MOD
        return (num1 * num2) % MOD;
    }
};