class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* odd=head;
        ListNode* even=head->next;

        ListNode* oddPtr=head;
        ListNode* evenPtr=head->next;

        while(evenPtr && evenPtr->next){
            oddPtr->next=evenPtr->next;
            oddPtr=oddPtr->next;

            evenPtr->next=oddPtr->next;
             evenPtr=evenPtr->next;

        }
        oddPtr->next=even;

   return odd;
    }
};