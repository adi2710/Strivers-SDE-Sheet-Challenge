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

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head == nullptr)
        return false;
    Node *slow = head, *fast = head;
    do{
        slow = slow -> next;
        if(fast -> next == nullptr)
            return false;
        fast = fast -> next -> next;
    }while(slow != fast && fast != nullptr);
    if(fast == nullptr)
        return false;
    return true;
}