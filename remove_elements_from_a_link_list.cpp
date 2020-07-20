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
    ListNode* removeElements(ListNode* head, int val) {
        // 1->2->6->3->4->5->6, val = 6
        // 1->2->3->4->5
        // 6->1->2->3
        ListNode *curr = head; 
        //Listnode *curr_next = NULL;
        while(head != NULL && head->val  == val)
            head = head->next;
        while (curr != NULL && curr->next != NULL ){ //&& curr_next != NULL){
            if(curr->next->val == val){
                curr->next = curr->next->next;
            }
            else curr= curr->next;            
        }
        return head;
    }
};
