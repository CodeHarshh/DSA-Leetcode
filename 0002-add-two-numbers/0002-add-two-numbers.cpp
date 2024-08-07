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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;
        int carry = 0;
        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;
            it->next = new ListNode(digit);
            it = it->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            // or use this
            // if (l1 != nullptr) l1 = l1->next;
            // else l1 = nullptr;

            // if (l2 != nullptr) l2 = l2->next;
            // else l2 = nullptr;
        }
        ListNode* finalans = ans->next;
        delete ans;
        return finalans;
    }
};