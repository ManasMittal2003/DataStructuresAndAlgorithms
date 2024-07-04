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

Node* deleteMiddle(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node *fast=head;
    Node *slow=head;
    Node *prev=NULL;
    while(fast!=NULL&&fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    slow->next=NULL;
    delete slow;
    return head;
    /* just maintaining a previous pointer which is moving just behind
    to slow so when slow reaches to the middle node we can delete the mid
    using previous pointer easily*/
}
