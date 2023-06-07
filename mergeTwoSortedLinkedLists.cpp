#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *dummy = new Node<int>(-1), *tmp = dummy;
    while(first != nullptr && second != nullptr)
    {
        if(first -> data <= second -> data)
            tmp -> next = first, first = first -> next;
        else
            tmp -> next = second, second = second -> next;
        tmp = tmp -> next;
    }
    if(first != nullptr)
        tmp -> next = first;
    else
        tmp -> next = second;
    tmp = dummy -> next;
    return tmp;
}