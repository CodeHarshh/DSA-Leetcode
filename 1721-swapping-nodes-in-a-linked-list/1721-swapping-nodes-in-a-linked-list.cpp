
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        
        int pos = 1 ,lastPos = cnt - k + 1;
        temp = head;
        ListNode* first = NULL;
        ListNode* last = NULL;
        while (temp != NULL) {
            if (pos == k) first = temp;
            if (pos == lastPos) last = temp;
            temp = temp->next;
            pos++;
        }
        if (first && last) {
            int temp1;
            temp1 = first->val;
            first->val = last->val;
            last->val = temp1;
        }
        return head;
    }
};