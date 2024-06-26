/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
    };

************************************************************/

void deleteNode(Node* node) {
    Node *previous=node->prev;
    Node *front=node->next;
    previous->next=front;
    if(front){
        front->prev=previous;
    }
    delete node;
}
