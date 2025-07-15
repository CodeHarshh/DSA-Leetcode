
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head )return head;

        int cnt = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
       
        int pos=cnt-n+1;
        temp=head;

       if (pos == 1) {
        return head->next;
    }


        for(int i=1;i<pos && temp!=NULL ;i++){
            prev=temp;
            temp=temp->next;
        }

        
    prev->next=temp->next;
       delete temp;
       return head;

    }

    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if ((head && head->next == NULL) && n == 1)
    //         return NULL;
    //     if (!head || !head->next)
    //         return head;
    //     ListNode* temp = head;
    //     ListNode* prev = NULL;
    //     int cnt = 0;
    //     while (temp) {
    //         cnt++;
    //         temp = temp->next;
    //     }
    //     int pos = cnt - n + 1;
    //     temp = head;
    //     for (int i = 1; i < pos; i++) {
    //         prev = temp;
    //         temp = temp->next;
    //     }
    //   //If prev is NULL, it means that the node to be removed is the head
    //   node
    //     if (prev == NULL) {
    //         head = head->next;
    //         return head;
    //     } else {
    //         prev->next = prev->next->next;
    //         return head;
    //     }

    //     return head;
    // }
};