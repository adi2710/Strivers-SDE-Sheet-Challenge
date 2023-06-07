#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverseList(Node *start, Node *end)
{
	Node *prev = nullptr, *cur = start;
	while(cur != end)
	{
		Node *next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	Node *dummy = new Node(-1), *prev = dummy, *cur = head;
	dummy -> next = head;
	int pos = 0;
	while(cur != nullptr && pos < n)
	{
		if(b[pos] == 0)
		{
			pos++;
			continue;
		}
		Node *next = cur;
		int cnt = 0;
		while(next != nullptr && cnt < b[pos])
		{
			next = next -> next;
			cnt++;
		}
		Node *new_head = reverseList(cur, next);
		prev -> next = new_head;
		cur -> next = next;
		prev = cur;
		cur = next;
		pos++;
	}
	cur = dummy -> next;
	delete(dummy);
	return cur;
}