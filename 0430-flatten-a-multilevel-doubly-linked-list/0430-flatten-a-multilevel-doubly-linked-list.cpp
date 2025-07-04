class Solution {
public:
    Node* solve(Node* head) {
        if (head == NULL)return NULL;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* frwd = curr->next;

                Node* Flatten = solve(curr->child);
                curr->next = Flatten;
                curr->next->prev = curr; // double L.L
                curr->child = NULL;

                while (curr->next != NULL) {
                    curr = curr->next;
                }
                if (frwd != NULL) {
                    curr->next = frwd;
                    frwd->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }



















    // Node* solve(Node* head) {
    //     if (head == NULL)
    //         return NULL;
    //     Node* start = head;
    //     Node* tail = start;

    //     while (start != NULL) {
    //         if (start->child) {
    //             Node* childtail = solve(start->child);

    //             // flatten's work
    //             Node* temp = start->next;
    //             start->next = start->child;
    //             start->next->prev = start;
    //             childtail->next = temp;
    //             if (temp != NULL) {
    //                 temp->prev = childtail;
    //             }
    //             start->child = NULL;
    //         }
    //         tail = start;
    //         start = start->next;
    //     }
    //     return tail;
    // }

    // Node* flatten(Node* head) {
    //     solve(head);
    //     return head;
    // }
};