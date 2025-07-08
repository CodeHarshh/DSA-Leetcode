
class Solution {
public:

    ListNode* findMid(ListNode* head) {
        if(!head) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;        
            
        }
        return prev;   // return Node before mid
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(!left) return right;
        if(!right) return left;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(left&& right){
           if(left->val <= right->val ){
          temp->next=left;
          temp=temp->next;
          left=left->next;
        }
        else{
              temp->next=right;
          temp=temp->next;
          right=right->next;
        }  
        }

        if(left) temp->next=left;

        if(right)temp->next=right;
        ListNode* ans=dummy->next;
       delete dummy;
       return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* left=head;
        ListNode* mid=findMid(head);
      ListNode* right = mid->next;
mid->next = NULL;

        left=sortList(left);
        right=sortList(right);

        ListNode* mergeList=mergeTwoLists(left,right);

        return mergeList;
        
    }


    // ListNode* findMid(ListNode* head) {
    //     ListNode* fast = head->next;
    //     ListNode* slow = head;
    //     while (fast && fast->next) {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }
    // ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
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
    //       return ans->next;
    // }

    // ListNode* sortList(ListNode* head) {
    //     if (head == NULL || head->next == NULL) return head;
    //     ListNode* mid = findMid(head);
    //     ListNode* left = head;
    //     ListNode* right = mid->next;
    //     mid->next = NULL;

    //     left = sortList(left);
    //     right = sortList(right);
    //     ListNode* mergerlist = mergeTwoLists(left, right);
    //     return mergerlist;
    // }
};