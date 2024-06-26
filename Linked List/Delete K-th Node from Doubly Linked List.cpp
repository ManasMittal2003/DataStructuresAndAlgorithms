/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */

Node *deleteNode(Node *head, int k){
    if(k==1){
        Node *temp=head;
        head=head->next;
        temp->next=nullptr;
        head->prev=nullptr;
        free(temp);
        return head;
    }
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node *previous=temp->prev;
    Node *front=temp->next;
    previous->next=front;
    if(front!=NULL){
        front->prev=previous;
    }
    temp->next=temp->prev=nullptr;
    free(temp);
    return head;
}
