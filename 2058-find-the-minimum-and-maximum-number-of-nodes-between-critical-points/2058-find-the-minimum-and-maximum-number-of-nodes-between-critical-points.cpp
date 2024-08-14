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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* prev = head;
        if (!prev)
            return ans;
        ListNode* curr = head->next;
        if (!curr)
            return ans;
        ListNode* nxt = head->next->next;
        if (!nxt)
            return ans;

        int firstcp = -1;
        int lastcp = -1;
        int min_dist = INT_MAX;

        int i = 1;
        while (nxt) {
            bool iscp = false;
            ;
            if (curr->val > prev->val && curr->val > nxt->val ||
                curr->val < prev->val && curr->val < nxt->val) {
                iscp = true;
            }

            if (iscp) {
                if (firstcp == -1)
                    firstcp = i;
                else
                    min_dist = min(min_dist, i - lastcp);
                lastcp = i;
            }

            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
            i++;
        }
        // if only one cp was present
        if (lastcp == firstcp) {
            return ans;
        } else {
            ans[0] = min_dist;
            ans[1] = lastcp - firstcp;
        }
        return ans;
    }
};