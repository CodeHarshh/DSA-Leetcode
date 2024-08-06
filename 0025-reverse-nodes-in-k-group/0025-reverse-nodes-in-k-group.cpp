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
    int getlength(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;

        int len = getlength(head);
        if (len < k) {
            return head;
        }

        ListNode* prev = NULL ;
        ListNode* curr = head;
        int position = 0;

        while (position < k) {
            ListNode* frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
            position++;
        }
        if (curr != NULL) {
            ListNode* reccursiveHead =reverseKGroup(curr,k);
            head->next=reccursiveHead;
        }
        return prev;
    }
};