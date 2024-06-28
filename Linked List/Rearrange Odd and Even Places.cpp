/****************************************************************
Following is the Linked list node structure already written

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

Node* oddEvenList(Node* head)
{
    if(head->next==NULL){
        return head;
    }
	Node *t1=head;
    Node *t2=head->next;
    Node *h2=t2;
    while(t2!=NULL&&t2->next!=NULL){
        if (t2->next) {
          t1->next = t2->next;
          t1 = t1->next;
        }
        t2->next=t1->next;
        t2=t2->next;
    }
    if(t2){
        t2->next=nullptr;
    }
    t1->next=h2;
    return head;

}
