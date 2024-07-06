class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *i = list1;
        ListNode *j = list2;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        while (i != nullptr && j != nullptr) {
            ListNode *temp = new ListNode();
            if (i->val <= j->val) {
                temp->val = i->val;
                if (head == nullptr) {
                    head = tail = temp;
                    i = i->next;
                } else {
                    tail->next = temp;
                    tail = temp;
                    i = i->next;
                }
            } else {
                temp->val = j->val;
                if (head == nullptr) {
                    head = tail = temp;
                    j = j->next;
                } else {
                    tail->next = temp;
                    tail = temp;
                    j = j->next;
                }
            }
        }
        while (i != nullptr) {
            ListNode *temp = new ListNode();
            temp->val = i->val;
            if (head == nullptr) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            i = i->next;
        }

        while (j != nullptr) {
            ListNode *temp = new ListNode();
            temp->val = j->val;
            if (head == nullptr) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            j = j->next;
        }

        return head;
    }
};
