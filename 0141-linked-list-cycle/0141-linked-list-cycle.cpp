/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // m1
        // unordered_map<ListNode* ,bool>m;
        // ListNode* temp=head;
        
        // while(temp!=NULL){
        // if(m[temp]==true)return true;
        // else m[temp]=true;

        // temp=temp->next;
        // }
        // return false;

        //m2 
        ListNode* fast=head;
          ListNode* slow=head;
          while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
          }
       return false;
    }
};