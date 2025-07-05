
class Solution {
public:

    ListNode* mergeNodes(ListNode* head) {
     if(!head) return NULL;
     
     int sum=0;

     ListNode* dummy=new ListNode(-1);
     ListNode* temp=dummy;

     ListNode* it=head;

     while(it!=NULL){
        if(it->val==0){
            if(sum>0){
                temp->next=new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
        }
        else{
            sum=sum+ (it->val);
        }
          it=it->next;
     }
return dummy->next;
    }

















    // ListNode* mergeNodes(ListNode* head) {
    //     ListNode* newnode = new ListNode(-1);
    //     ListNode* temp = newnode;

    //     int sum = 0;
    //     ListNode* it = head->next;
    //     while (it != NULL) {
    //         if (it->val == 0) {
    //             if (sum > 0) {
    //                 temp->next = new ListNode(sum);
    //                 temp = temp->next;
    //                 sum = 0;
    //             }
    //         } else {
    //             sum = sum + it->val;
    //         }
    //         it = it->next;
    //     }
    //     return newnode->next;
    // }
};