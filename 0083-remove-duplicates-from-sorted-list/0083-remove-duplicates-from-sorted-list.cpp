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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* temp = head->next;
        ListNode* temp2 = head;

        while (temp != NULL) {
            if (temp2->val == temp->val) {
                temp2->next = temp->next;
                delete temp;
                temp = temp2->next;
            } else {
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};