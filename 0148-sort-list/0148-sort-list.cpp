
class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;
                mptr = left;
                left = left->next;
            } else {
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        if (left) mptr->next = left;
        if (right) mptr->next = right;
          return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        ListNode* mergerlist = mergeTwoLists(left, right);
        return mergerlist;
    }
};