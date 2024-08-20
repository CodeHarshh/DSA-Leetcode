/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        ListNode *temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len=getLen(head);
        int actualrotate=(k%len);
        if(actualrotate==0) return head;
        int newlastnodepos=len-actualrotate-1;

        ListNode* newnodehead=NULL;
        ListNode* newLastnode=head;
        for(int i=0;i<newlastnodepos;i++){
            newLastnode=newLastnode->next;
        }
        newnodehead=newLastnode->next;

        newLastnode->next=NULL;
        
        ListNode* it=newnodehead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newnodehead;


    }
};