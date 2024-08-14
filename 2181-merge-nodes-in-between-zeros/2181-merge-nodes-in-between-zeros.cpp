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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newnode = new ListNode(-1);
        ListNode* temp = newnode;

        int sum = 0;
        ListNode* it = head->next;
        while (it != NULL) {
            if (it->val == 0) {
                if (sum > 0) {
                    temp->next = new ListNode(sum);
                    temp = temp->next;
                    sum = 0;
                }
            } else {
                sum = sum + it->val;
            }
            it = it->next;
        }
        return newnode->next;
    }
};