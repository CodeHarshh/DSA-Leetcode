
class Solution {
public:
    // int getlength(ListNode* head) {
    //     if (head == NULL)
    //         return 0;
    //     ListNode* temp = head;
    //     int cnt = 0;
    //     while (temp != NULL) {
    //         cnt++;
    //         temp = temp->next;
    //     }
    //     return cnt;
    // }

    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (head == NULL || head->next == NULL)
    //         return head;

    //     int len = getlength(head);

    //     if (len < k)return head;

    //     ListNode* dummy = new ListNode(-1);

    //     dummy->next = head;

    //     ListNode* curr = NULL;
    //     ListNode* prev = dummy;
    //     ListNode* nex = NULL;

    //     while (len >= k) {

    //         curr = prev->next;
    //         nex = curr->next;

    //         for (int i = 1; i < k; i++) {
    //             ListNode* temp = nex->next; // we will iterate from k=1 to
    //             nex->next = prev->next;   // every iteration we change
    //             two element place prev->next = nex; // bring nex in front
    //             curr->next = temp; // connect curr to rest part
    //             nex = temp;        // move nex ahead
    //         }
    //         len = len - k;
    //         prev = curr;
    //     }
    //     return dummy->next;
    // }

    int getlength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || !head->next) return head;

        int len = getlength(head);

        if (len < k) return head;

            ListNode* dummy= new ListNode(-1);
            dummy->next=head;
            ListNode* prev=dummy;
             ListNode* nxt=NULL;
              ListNode* curr=NULL;

        while (len >= k) {

             curr=prev->next;
             nxt=curr->next;

            for (int i = 1; i < k; i++) {
            curr->next=nxt->next;
            nxt->next=prev->next;
            prev->next=nxt;
            nxt=curr->next;
            }

            len=len-k;  // sub len
            prev=curr;   // move prev pointer to current
        }
        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }

    //  int getlength(ListNode* head) {
    //     ListNode* temp = head;
    //     int cnt = 0;
    //     while (temp != NULL) {
    //         cnt++;
    //         temp = temp->next;
    //     }
    //     return cnt;
    // }

    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (head == NULL)
    //         return head;
    //     if (head->next == NULL)
    //         return head;

    //     int len = getlength(head);
    //     if (len < k) {
    //         return head;
    //     }

    //     ListNode* prev = NULL ;
    //     ListNode* curr = head;
    //     int position = 0;

    //     while (position < k) {
    //         ListNode* frwd = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = frwd;
    //         position++;
    //     }
    //     if (curr != NULL) {
    //         ListNode* reccursiveHead =reverseKGroup(curr,k);
    //         head->next=reccursiveHead;
    //     }
    //     return prev;
    // }
};