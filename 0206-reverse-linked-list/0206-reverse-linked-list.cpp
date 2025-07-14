
class Solution {
public:
    ListNode* reverseList(ListNode*& prev, ListNode*& curr) {
     if(curr==NULL)return prev;
     ListNode* next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
     return reverseList(prev,curr);

    }
    ListNode* reverseList(ListNode* head) {
      ListNode* prev=NULL;
      ListNode* curr=head;
      ListNode* ans= reverseList(prev,curr);
      return ans;
    }
};