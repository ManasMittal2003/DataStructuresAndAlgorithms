/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {
    Node *head=new Node(arr[0]);
    Node *previous=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        previous->next=temp;
        temp->prev=previous;
        previous=temp;
    }
    return head;
}
