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

Node* findIntersection(Node *first, Node *second)
{
    int n1=0;
    int n2=0;
    Node *temp1=first;
    Node *temp2=second;
    Node *t1=temp1;
    Node *t2=temp2;
    while(temp1!=NULL){
        n1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        n2++;
        temp2=temp2->next;
    }
    int diff=abs(n2-n1);
    if(n2>n1){
        while(diff!=0){
            t2=t2->next;
            diff--;
        }
    }else if(n1>n2){
        while(diff!=0){
            t1=t1->next;
            diff--;
        }
    }
    while(t1!=NULL&&t2!=NULL){
        if(t1==t2){
            return t1;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return NULL;
}
