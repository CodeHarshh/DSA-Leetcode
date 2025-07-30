
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int carry = 0;
        while (t1 || t2) {

            int a = t1 ? t1->val : 0;
            int b = t2 ? t2->val : 0;

            int sum = a + b + carry;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            carry = sum / 10;
            t1 = t1 ? t1->next : NULL;
            t2 = t2 ? t2->next : NULL;
        }
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }

    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* ans = new ListNode(-1);
    //     ListNode* it = ans;
    //     int carry = 0;
    //     while (l1 || l2 || carry) {
    //         int a = l1 ? l1->val : 0;
    //         int b = l2 ? l2->val : 0;
    //         int sum = a + b + carry;
    //         int digit = sum % 10;
    //         carry = sum / 10;
    //         it->next = new ListNode(digit);
    //         it = it->next;

    //         l1 = l1 ? l1->next : NULL;
    //         l2 = l2 ? l2->next : NULL;
    //         // or use this
    //         // if (l1 != nullptr) l1 = l1->next;
    //         // else l1 = nullptr;

    //         // if (l2 != nullptr) l2 = l2->next;
    //         // else l2 = nullptr;
    //     }
    //     ListNode* finalans = ans->next;
    //     delete ans;
    //     return finalans;
    // }
};