#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverseList(LinkedListNode<int> *start)
{
    LinkedListNode<int> *prev = nullptr, *cur = start;
    while(cur != nullptr)
    {
        LinkedListNode<int> *next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == nullptr || head -> next == nullptr)
        return true;
    LinkedListNode<int> *slow = head, *fast = head, *prev = nullptr;
    while(fast != nullptr && fast -> next != nullptr)
    {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    LinkedListNode<int> *start = slow;
    if(fast != nullptr)
        start = start -> next;
    LinkedListNode<int> *head2 = reverseList(start);
    LinkedListNode<int> *tmp1 = head, *tmp2 = head2;
    bool ans = true;
    while(tmp1 != slow && tmp2 != nullptr)
    {
        if(tmp1 -> data != tmp2 -> data)
        {
            ans = false;
            break;
        }
        tmp1 = tmp1 -> next;
        tmp2 = tmp2 -> next;
    }
    head2 = reverseList(head2);
    if(fast != nullptr)
        slow -> next = head2;
    else
        prev -> next = head2;
    return ans;
}