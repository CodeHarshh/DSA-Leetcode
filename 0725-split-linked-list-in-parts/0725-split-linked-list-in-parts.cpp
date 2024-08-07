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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        int partSize = n / k;
        int ExtraSize = n % k;
        vector<ListNode*> ans(k, NULL);
        temp = head;

        for (int i = 0; i < k; i++) {
            ans[i] = temp;
            int currPartSize = partSize + (ExtraSize-- > 0 ? 1 : 0);
            for (int j = 0; j < currPartSize - 1; j++) {
                temp = temp->next;
            }
            if (temp != NULL) {
                ListNode* NextPartStart = temp->next;
                temp->next = NULL;
                temp = NextPartStart;
            }
        }
        return ans;
    }
};