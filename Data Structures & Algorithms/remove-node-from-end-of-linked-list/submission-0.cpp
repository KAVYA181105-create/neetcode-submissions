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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode * temp = head;
        while(temp!=0){
            count++;
            temp= temp->next;
        }
        // number of element to remove from front = count -n+ 1
        int n1 = count - n+1;
        if (n1 == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode * temp1 = head;
        ListNode * prev = NULL;
        int n2 =1;
        while(n2!=n1){
            prev= temp1;
            temp1 = temp1->next;
            n2++;
        }
        prev->next = temp1->next;
        return head;
    }
};
