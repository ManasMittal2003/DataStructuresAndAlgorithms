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
void solve(Node *head,Node **newhead){
    if(head->next==NULL){
        *newhead=head;
        return;
    }
    solve(head->next,newhead);
    head->next->next=head;
}
Node* reverseLinkedList(Node *head)
{
    Node *newhead=NULL;
    solve(head,&newhead);
    head->next=NULL;
    return newhead;
}
