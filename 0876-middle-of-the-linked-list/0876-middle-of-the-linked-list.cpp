
class Solution {
public:


  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

      while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
      }
      return slow;
    }





    // ListNode* middleNode(ListNode* head) {

    //     ListNode* fast = head;
    //     ListNode* slow = head;

    //     while(fast->next && fast->next->next){
    //         fast=fast->next->next;
    //         slow=slow->next;
    //     }
    //     if(fast->next){  // we added this line because if it had two middle elements
    //         slow=slow->next;
    //     }
    //     return slow;
    // }
};