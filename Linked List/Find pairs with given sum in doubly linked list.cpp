/**
 * Definition of doubly linked list:
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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    Node *i=head;
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(i!=temp&&temp->next!=i){
        int d1=i->data;
        int d2=temp->data;
        if(d1+d2==k){
            ans.push_back({d1,d2});
            i=i->next;
            temp=temp->prev;
        }
        else if(d1+d2>k)
        {
            temp=temp->prev;
        }
        else{
            i=i->next;
        }
    }
    return ans;

    /* if there is odd linked list then temp and i will meet
    but incase of even linked list they will cross hence
    temp->next!=i will ensure this case*/
}
