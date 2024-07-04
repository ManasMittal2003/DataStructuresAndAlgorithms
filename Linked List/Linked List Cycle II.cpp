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

Node *firstNode(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            slow=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}
/*if head to slow is L1 then fast will be at 2L1 distance from 
head it means distance between slow and fast will be L1, let the 
distance between fast and slow be d now when fast and slow collided 
then fast has to move 2d to catch slow it means slow has moved d distance 
so we can say that length of loop is L1 + d now if slow to collision point
the distance is d then remaining would be L1 and head to starting node of 
loop the distance is L1 hence they meet at the starting point.*/


