
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        if (prev != NULL) {
            prev->next = NULL;
            node->left = sortedListToBST(head);
        }
        node->right = sortedListToBST(slow->next);
        return node;
    }
};