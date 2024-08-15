
class Solution {
public:
    void SanitiseMap(ListNode* curr, unordered_map<int, ListNode*>& m,int csum) {
        int temp = csum;
        while (curr != NULL) {
            temp = temp + curr->val;
            if (csum == temp) break;
            m.erase(temp);
            curr = curr->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head || head->next == NULL && head->val == NULL) return 0;
        unordered_map<int, ListNode*> m;
        ListNode* it = head;
        int csum = 0;
        while (it != NULL) {
            csum = csum + it->val;

            if (csum == 0) {
                head = it->next;
                m.clear();
            } else if (m.find(csum) != m.end()) {
                SanitiseMap(m[csum]->next, m, csum);
                m[csum]->next = it->next;
            } else {
                m[csum] = it;
            }
            it = it->next;
        }
        return head;
    }
};