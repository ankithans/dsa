// brute
// two traversals - one for counting
// second for reaching the mid
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *curr = head;
        while(curr -> next != NULL) {
            count++;
            curr = curr->next;
        }
        
        for(int i = 0; i < count/2; i++) {
            head = head->next;
        }
        
        return count%2 == 0 ? head : head->next;
    }
};

// optimal (fast-slow) (tortoise-hare)
// one traversal
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};