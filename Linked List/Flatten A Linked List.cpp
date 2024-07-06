/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node * merger(Node *l1,Node *l2){
	Node *head=NULL;
	Node *mover=NULL;
	while(l1!=NULL&&l2!=NULL){
		if(l1->data<=l2->data){
			Node *tempnode=new Node(l1->data);
			if(head==NULL){
				head=mover=tempnode;
			}else{
				mover->child=tempnode;
				mover=tempnode;
			}
			l1=l1->child;
		}else{
			Node *tempnode=new Node(l2->data);
			if(head==NULL){
				head=mover=tempnode;
			}else{
				mover->child=tempnode;
				mover=tempnode;
			}
			l2=l2->child;
		}
	}
	if(l1!=NULL){
			if(head==NULL){
				head=mover=l1;
			}else{
				mover->child=l1;
			}
			l1=l1->child;
	}
	else if(l2!=NULL){
			if(head==NULL){
				head=mover=l2;
			}else{
				mover->child=l2;
			}
			l2=l2->child;
	}
	head->next=NULL;
	return head;
}
Node* flattenLinkedList(Node* head) 
{
	if(head->next==NULL){
		return head;
	}
	Node *res=flattenLinkedList(head->next);
	Node *mergedhead=merger(head,res);
	return mergedhead;
}
