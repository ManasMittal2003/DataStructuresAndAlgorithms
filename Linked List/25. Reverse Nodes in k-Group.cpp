/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
    }
    ListNode* findnode(ListNode* temp, int& k) {
        int i = 1;
        while (temp != NULL && i != k) {
            temp = temp->next;
            i++;
        }
        if (i != k) {
            return NULL;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *prevnode = NULL;
        ListNode* knode;
        while (temp != NULL) {
            knode = findnode(temp, k);
            if (knode == NULL) {
                if (prevnode) {
                    prevnode->next = temp;
                }
                break;
            }
            ListNode* nextnode = knode->next;
            knode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = knode;
            } else {
                prevnode->next = knode;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};
