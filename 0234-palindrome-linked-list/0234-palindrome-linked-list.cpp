
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
        if (curr == NULL)
            return prev;
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        return reverse(prev, forward);
    }

    bool isPalindrome(ListNode* head) {
        ListNode* middle = getmiddle(head);
        ListNode* firsthalf = head;
        cout << firsthalf->val;
        ListNode* secondhalf = reverse(nullptr, middle);
        cout << secondhalf->val;

        while (firsthalf != NULL && secondhalf != NULL) {

            if (secondhalf->val == firsthalf->val) {
                firsthalf = firsthalf->next;
                secondhalf = secondhalf->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
