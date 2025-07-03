
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
    if(left==NULL)return right;
    if(right==NULL)return left;
    
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;

    while(left && right){
        if(left->val <= right->val){
         temp->next=left;
         temp=left;
         left=left->next;
        }

        else if(right->val <= left->val){
         temp->next=right;
         temp=right;
         right=right->next;
        }
    }

    if(left) temp->next=left;
    if(right) temp->next=right;

    return dummy->next;
   
    }










    //    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

    //     if (!left) return right;
    //     if (!right) return left;

    //     ListNode* ans = new ListNode(-1);
    //     ListNode* mptr = ans;

    //     while (left && right) {
    //         if (left->val <= right->val) {
    //             mptr->next = left;
    //             mptr = left;
    //             left = left->next;
    //         } else {
    //             mptr->next = right;
    //             mptr = right;
    //             right = right->next;
    //         }
    //     }
    //     if (left) mptr->next = left;
    //     if (right) mptr->next = right;
    //     return ans->next;
    // }
};