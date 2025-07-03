
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        vector<ListNode*> ans(k, NULL);
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        int eachPartSize = n / k;
        int extraSize = n % k;

        temp = head;
        for (int i = 0; i < k; i++) {
            ans[i] = temp;
            int currPartSize = eachPartSize + (extraSize-- > 0 ? 1 : 0);

            for (int i = 0; i < currPartSize - 1; i++) {
                temp = temp->next;
            }
            if (temp != NULL) {
                ListNode* next = temp->next;
                temp->next = NULL;
                temp = next;
            }
        }
        return ans;
    }

    //  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    //     int n = 0;
    //     ListNode* temp = head;
    //     while (temp != NULL) {
    //         n++;
    //         temp = temp->next;
    //     }

    //     int partSize = n / k;
    //     int ExtraSize = n % k;
    //     vector<ListNode*> ans(k, NULL);
    //     temp = head;

    //     for (int i = 0; i < k; i++) {
    //         ans[i] = temp;
    //         // Add 1 extra node to this part if any extras are left
    //         int currPartSize = partSize + (ExtraSize-- > 0 ? 1 : 0);
    //         for (int j = 0; j < currPartSize - 1; j++) {
    //             temp = temp->next;
    //         }
    //         if (temp != NULL) {
    //             ListNode* NextPartStart = temp->next;
    //             temp->next = NULL;
    //             temp = NextPartStart;
    //         }
    //     }
    //     return ans;
    // }
};