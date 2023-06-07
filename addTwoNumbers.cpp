/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *dummy = new Node(-1), *tmp = dummy;
    int carry = 0;
    while(num1 != nullptr && num2 != nullptr)
    {
        int sum = num1 -> data + num2 -> data + carry;
        tmp -> next = new Node(sum % 10);
        carry = sum / 10;
        tmp = tmp -> next;
        num1 = num1 -> next;
        num2 = num2 -> next;
    }
    while(num1 != nullptr)
    {
        int sum = num1 -> data + carry;
        tmp -> next = new Node(sum % 10);
        carry = sum / 10;
        tmp = tmp -> next;
        num1 = num1 -> next;
    }
    while(num2 != nullptr)
    {
        int sum = num2 -> data + carry;
        tmp -> next = new Node(sum % 10);
        carry = sum / 10;
        tmp = tmp -> next;
        num2 = num2 -> next;
    }
    if(carry > 0)
        tmp -> next = new Node(carry);
    tmp = dummy -> next;
    delete(dummy);
    return tmp;
}
