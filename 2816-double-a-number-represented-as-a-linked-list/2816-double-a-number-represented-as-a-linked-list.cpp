
class Solution {
public:
    void solve(ListNode* head, int& carry) {
        if (!head)
            return;
        solve(head->next, carry);

        int prod = (head->val * 2) + carry;
        head->val = prod % 10;
        carry = prod / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);
        if (carry != NULL) {
            ListNode* newnode = new ListNode(carry);
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
};