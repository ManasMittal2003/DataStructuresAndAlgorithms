/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    Node *temp=head;
    while(temp!=NULL&&temp->data==k){
        head=head->next;
        temp=temp->next;
    }
    if(head==NULL){
        return head;
    }
    head->prev=NULL;
    while(temp!=NULL){
        if(temp->data==k){
            Node *del=temp;
            Node *prev=temp->prev;
            Node *front=temp->next;
            prev->next=front;
            if (front) {
              front->prev = prev;
            }
            temp=front;
            del->next=NULL;
            delete del;
        }else{
            temp=temp->next;
        }
    }
    return head;
}
