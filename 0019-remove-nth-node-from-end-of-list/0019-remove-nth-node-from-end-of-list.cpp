
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ((head && head->next == NULL) && n == 1)
            return NULL;
        if (!head || !head->next)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 0;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        int pos = cnt - n + 1;
        temp = head;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            head = head->next;
            return head;
        } else {
            prev->next = prev->next->next;
            return head;
        }

        return head;
    }
};