/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head) {
        if (head == NULL)
            return NULL;
        Node* start = head;
        Node* tail = start;

        while (start != NULL) {
            if (start->child) {
                Node* childtail = solve(start->child);

                // flatten's work
                Node* temp = start->next;
                start->next = start->child;
                start->next->prev = start;
                childtail->next = temp;
                if (temp != NULL) {
                    temp->prev = childtail;
                }
                start->child = NULL;
            }
            tail = start;
            start = start->next;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};