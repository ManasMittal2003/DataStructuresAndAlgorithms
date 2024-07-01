/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
int solve(Node *temp){
    if(temp==NULL){
        return 1;
    }
    int carry1=solve(temp->next);
    if((temp->data+carry1)<10){
        temp->data=temp->data+carry1;
        carry1=0;
    }else{
        temp->data=0;
        carry1=1;
    }
    return carry1;
}
Node *addOne(Node *head)
{
    Node *temp=head;
    int extra=solve(temp);
    if(extra!=0){
        Node *newnode=new Node(1);
        newnode->next=head;
        head=newnode;
    }
    return head;
}
