
class Solution {
public:

ListNode* deleteDuplicates(ListNode* head) {
       if(!head) return NULL;

       ListNode* curr=head;
       ListNode* frwd=head->next;

       while(frwd!=NULL){
        if(curr->val==frwd->val){
            curr->next=frwd->next;
            delete frwd;
            frwd=curr->next;
        }else{
            curr=curr->next;
            frwd=frwd->next;
        }
       }

return head;

    }







    // ListNode* deleteDuplicates(ListNode* head) {
    //     if (head == NULL) return NULL;

    //     ListNode* temp = head->next;
    //     ListNode* temp2 = head;

    //     while (temp != NULL) {
    //         if (temp2->val == temp->val) {
    //             temp2->next = temp->next;
    //             delete temp;
    //             temp = temp2->next;
    //         } else {
    //             temp = temp->next;
    //             temp2 = temp2->next;
    //         }
    //     }
    //     return head;
    // }
};