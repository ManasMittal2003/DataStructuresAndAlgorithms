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

bool detectCycle(Node *head)
{
	Node *slow=head;
    Node *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
    
    /* it is suree that if there exists a loop in list then
    slow and fast will definitely collide because fast is moving 2 
    steps towards slow and slow is moving 1 step away from fast
    so if we calculate net then the result will be : fast is moving 
    1 towards slow so after each movement the distance between fast and slow 
    will reduce by 1 and hence at a point this distance will become 0
    and this is the point where they collide. */
}
