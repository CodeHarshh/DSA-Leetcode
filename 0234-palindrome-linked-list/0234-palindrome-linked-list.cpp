
class Solution {
public:
    ListNode* getmiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* prev, ListNode* curr) {
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* middle = getmiddle(head);
        ListNode* firsthalf = head;
        ListNode* secondhalf = reverse(nullptr, middle);

        while (firsthalf != NULL && secondhalf != NULL) {
            if (firsthalf->val != secondhalf->val)
                return false;
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }
        return true;
    }
};