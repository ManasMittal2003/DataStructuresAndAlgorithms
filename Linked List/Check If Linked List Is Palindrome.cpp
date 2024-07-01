/****************************************************************

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

*****************************************************************/
Node * reverse(Node *head){
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        Node *forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *newhead=slow->next;
    newhead=reverse(newhead);
    Node *first=head;
    Node *second=newhead;
    while(second->next!=NULL){
        if(first->data!=second->data){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}
