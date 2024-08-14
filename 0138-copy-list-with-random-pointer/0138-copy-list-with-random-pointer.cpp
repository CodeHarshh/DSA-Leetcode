/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head, unordered_map < Node*, Node*>& m) {
        if (!head)
            return NULL;
    
        Node* newnode = new Node(head->val);
          m[head]=newnode;
        newnode->next = solve(head->next, m);
        if(head->random){
            newnode->random=m[head->random];
        }
        return newnode;
    }
    Node* copyRandomList(Node* head) {
    unordered_map<Node* , Node*>m;
    return solve(head, m);
    
    
}
}
;