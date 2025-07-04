
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int cntA = 0, cntB = 0;

        while (a != NULL) {
            cntA++;
            a = a->next;
        }
        while (b != NULL) {
            cntB++;
            b = b->next;
        }
        int k = abs(cntA - cntB);
        a = headA;
        b = headB;

            if (cntA > cntB) {
                for (int i = 0; i < k; i++) {
                    a = a->next;
                }
            } else if (cntB > cntA) {
                for (int i = 0; i < k; i++) {
                    b = b->next;
                }
            }
        

        while (a || b) {
            if (a == b)return a;

            a = a->next;
            b = b->next;
        }
        return NULL;
    }






    // ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    //     ListNode* temp1 = headA;
    //     ListNode* temp2 = headB;
    //     int cnt1 = 0, cnt2 = 0;
    //     while (temp1) {
    //         cnt1++;
    //         temp1 = temp1->next;
    //     }
    //     while (temp2) {
    //         cnt2++;
    //         temp2 = temp2->next;
    //     }
    //     temp1 = headA;
    //     temp2 = headB;
    //     int k = abs(cnt1 - cnt2);
    //     if (cnt1 > cnt2) {
    //         for (int i = 0; i < k; i++) {
    //             temp1 = temp1->next;
    //         }
    //     } else {
    //         for (int i = 0; i < k; i++) {
    //             temp2 = temp2->next;
    //         }
    //     }
    //     while (temp1 || temp2) {
    //         if (temp1 == temp2) {
    //             return temp1;
    //         }
    //         temp1 = temp1->next;
    //         temp2 = temp2->next;
    //     }
    //     return NULL;
    // }
};