/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *slow = head, *fast = head;
    do{
        slow = slow -> next;
        if(fast -> next == nullptr)
            return nullptr;
        fast = fast -> next -> next;
    }while(slow != fast && fast != nullptr);
    if(fast == nullptr)
        return nullptr;
    slow = head;
    while(slow != fast)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}