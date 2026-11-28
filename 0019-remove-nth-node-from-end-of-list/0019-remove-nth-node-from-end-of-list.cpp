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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        if(!head || n==0){
            return head;
        }
        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        int toDel = len-n;
        temp = dummy;
        for(int i = 0; i<toDel; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return dummy->next;
    }
};