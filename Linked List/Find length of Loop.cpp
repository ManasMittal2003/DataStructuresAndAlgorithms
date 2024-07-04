/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            fast=fast->next;
            int cnt=1;
            while(fast!=slow){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;

    /*if the fast and slow pointers collide then it is sure that fast
    pointer will definitely comeback to slow as they are in a loop
    hence we will move the fast pointer to slow with a counter*/
}
