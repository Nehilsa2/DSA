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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head) return NULL;

        ListNode*temp = head;
        ListNode*itr = head;
        int lastnode = head->val;

        while(temp->next){
            if(temp->next->val==lastnode) {
                temp = temp->next;
                continue;
            }

            itr->next = temp->next;
            itr = itr->next;

            temp = itr;
            lastnode = itr->val; 
        }

        itr->next = NULL;

        return head;
    }

};