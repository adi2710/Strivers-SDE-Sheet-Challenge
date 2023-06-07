/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *child;
 * 		Node *child;
 *		Node() : data(0), child(nullptr), child(nullptr){};
 *		Node(int x) : data(x), child(nullptr), child(nullptr) {}
 *		Node(int x, Node *child, Node *child) : data(x), child(child), child(child) {}
 * };
 */

Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    Node *dummy = new Node(-1), *tmp = dummy;
    while(first != nullptr && second != nullptr)
    {
        if(first -> data <= second -> data)
            tmp -> child = first, first = first -> child;
        else
            tmp -> child = second, second = second -> child;
        tmp = tmp -> child;
    }
    if(first != nullptr)
        tmp -> child = first;
    else
        tmp -> child = second;
    tmp = dummy -> child;
    return tmp;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	Node *cur = head;
	head = nullptr;
	while(cur != nullptr)
	{
		Node *next = cur -> next;
		cur -> next = nullptr;
		head = sortTwoLists(head, cur);
		cur = next;
	}
	return head;
}