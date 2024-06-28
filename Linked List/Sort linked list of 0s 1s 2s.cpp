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

Node* sortList(Node *head){
    Node *zero=NULL;
    Node *zeromover=NULL;
    Node *one=NULL;
    Node *onemover=NULL;
    Node *two=NULL;
    Node *twomover=NULL;
    Node *temp=head;
    while(temp!=NULL){
        Node *newnode=new Node(temp->data);
        if(temp->data==0){
            if(zero==NULL){
                zero=zeromover=newnode;
            }else{
                zeromover->next=newnode;
                zeromover=newnode;
            }
        }else if(temp->data==1){
            if(one==NULL){
                one=onemover=newnode;
            }else{
                onemover->next=newnode;
                onemover=newnode;
            }
        }else{
            if(two==NULL){
                two=twomover=newnode;
            }else{
                twomover->next=newnode;
                twomover=newnode;
            }
        }
        temp=temp->next;
    }
    zeromover->next=one;
    onemover->next=two;
    return zero;
}
