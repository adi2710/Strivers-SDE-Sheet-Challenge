/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head == nullptr)
          return head;
     int size = 0;
     Node *tmp = head, *last = head;
     while(tmp != nullptr)
          last = tmp, tmp = tmp -> next, size++;
     k %= size;
     if(k == 0)
          return head;
     int pos = 0;
     tmp = head;
     while(pos < size - k - 1)
     {
          tmp = tmp -> next;
          pos++;
     }
     Node *newHead = tmp -> next;
     tmp -> next = nullptr;
     last -> next = head;
     return newHead;
}