
class Solution {
public:
    //  swapping the values question
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return head;

        int cnt = 0;
        ListNode* first = head;
        ListNode* last = head;

        while (first != NULL) {
            cnt++;
            first = first->next;
        }
       
        first = head;
        int Lpos=cnt-k+1 ,pos=1;

        ListNode* temp = head;
        while(temp!=NULL){
            if(pos==k) first=temp;
            if(pos==Lpos) last=temp;
            pos++;
            temp=temp->next;
        }

        if(first&&last){
         
            int temp=first->val;
            first->val=last->val;
            last->val=temp;
        }

return head;

    }

    // ListNode* swapNodes(ListNode* head, int k) {
    //     ListNode* temp = head;
    //     int cnt = 0;
    //     while (temp != NULL) {
    //         cnt++;
    //         temp = temp->next;
    //     }

    //     int pos = 1 ,lastPos = cnt - k + 1;
    //     temp = head;
    //     ListNode* first = NULL;
    //     ListNode* last = NULL;
    //     while (temp != NULL) {
    //         if (pos == k) first = temp;
    //         if (pos == lastPos) last = temp;
    //         temp = temp->next;
    //         pos++;
    //     }
    //     if (first && last) {
    //         int temp1;
    //         temp1 = first->val;
    //         first->val = last->val;
    //         last->val = temp1;
    //     }
    //     return head;
    // }
};