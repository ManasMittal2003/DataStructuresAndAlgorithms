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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head=NULL;
    Node *mover=NULL;
    int carry=0;
    while(num1!=NULL&&num2!=NULL){
        int sum=(num1->data+num2->data+carry);
        carry=sum/10;
        Node *temp=new Node(sum%10);
        if(head==NULL){
            head=mover=temp;
        } else {
            mover->next = temp;
            mover = temp;
            
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1!=NULL){
        int sum=(num1->data+carry);
        carry=sum/10;
        Node *temp=new Node(sum%10);
        if(head==NULL){
            head=mover=temp;
        }
        else{
            mover->next=temp;
            mover=temp;
        }
        num1=num1->next;
    }
    while(num2!=NULL){
        int sum=(num2->data+carry);
        carry=sum/10;
        Node *temp=new Node(sum%10);
        if(head==NULL){
            head=mover=temp;
        }
        else{
            mover->next=temp;
            mover=temp;
        }
        num2=num2->next;
    }
    while(carry!=0){
        int sum=(carry);
        carry=sum/10;
        Node *temp=new Node(sum%10);
        if(head==NULL){
            head=mover=temp;
        }
        else{
            mover->next=temp;
            mover=temp;
        }  
    }
    return head;
}
