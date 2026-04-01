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
    ListNode* swapPairs(ListNode* head) {

        if(!head){
            return NULL;
        }

        if(!head->next){
            return head;
        }
        ListNode*first = head;
        ListNode*second = head->next;

        ListNode*newHead = second;

        ListNode*temp1 = NULL;
        while(first && second){
            
            ListNode*temp = second->next;

            second->next = first;
            first->next = temp;

            if(temp1){
                temp1->next = second;
            }
            temp1 = first;

            first = temp;
            if(first){
                second = first->next;

            }
        }

        return newHead;
    }
};