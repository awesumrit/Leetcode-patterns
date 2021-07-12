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
    bool haskElements(ListNode* head, int k) 
    {
        ListNode* tmp = head;
        while(tmp!=NULL)
        {
            k--;
            tmp = tmp->next;
        }
       // cout<<k<<endl;
        if(k>0) return false;
        return true;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        
        if(!haskElements(head,k)) return head;
       // cout<<head->val<<endl;
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        int x = k;
        while(x>0 && curr)
        {
            x--;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            
        }
        head->next = reverseKGroup(curr,k);
        return prev;
        
    }
};
