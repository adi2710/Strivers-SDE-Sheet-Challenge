/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node *dummy = new Node(-1, head), *prev = dummy, *slow = head, *fast = head;
    int n = 0;
    while(n < K)
    {
        fast = fast -> next;
        n++;
    }
    while(fast != nullptr)
    {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next;
    }
    prev -> next = slow -> next;
    delete(slow);
    Node *ans = dummy -> next;
    delete(dummy);
    return ans;
}
