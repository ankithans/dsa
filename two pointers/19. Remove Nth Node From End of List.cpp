// brute - couldn't pass all test cases
// count the elements then delete count-nth element from start
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        
        int count = 0;
        ListNode *curr = head;
        
        while(curr->next) {
            count++;
            curr = curr->next;
        }
        
        curr = head;
        for(int i = 0; i < count-n; i++) {
            curr = curr->next;
        }
        
        ListNode *temp = curr->next->next;
        delete curr->next;
        curr->next = temp;
        
        return head;
    }
};

// optimal two pointers
// slow,fast=head;
// take fast to n;
// take slow, fast upto !fast->next
// then we are at n'th element from last to be deleted
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        
        while(n--)
            fast = fast->next;
        
        if(!fast) return head->next;
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};