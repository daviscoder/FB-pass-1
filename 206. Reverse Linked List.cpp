/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// iteration.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * p = NULL, * q = head;
        while (q) {
            ListNode * tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};

// recursion.
class Solution {
public:
    ListNode * helper (ListNode * head, ListNode * newHead) {
        if (head == NULL) {
            return newHead;
        }
        ListNode * next = head->next;
        head->next = newHead;
        return helper (next, head);
    }
    ListNode* reverseList(ListNode* head) {
        return helper (head, NULL);
    }
};
