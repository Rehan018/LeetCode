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

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {

        head = reverse(head);

        int mx = head->val;

        ListNode* curr = head;

        while (curr && curr->next) {

            if (curr->next->val < mx) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                mx = max(mx, curr->val);
            }
        }

        return reverse(head);
    }
};