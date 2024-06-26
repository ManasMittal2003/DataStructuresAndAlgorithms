/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    if(head==NULL){
        Node *temp=new Node(k);
        return temp;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newnode=new Node(k);
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}
