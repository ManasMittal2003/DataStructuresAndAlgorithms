/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    Node *fast=head;
    Node *slow=head;
    for(int i=1;i<=K;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        head=head->next;
        delete slow;
        return head;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node *delnode=slow->next;
    slow->next=slow->next->next;
    delnode->next=NULL;
    delete delnode;
    return head;
}
