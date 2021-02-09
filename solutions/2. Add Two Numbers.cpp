/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *start = new ListNode(0);
        ListNode *ourLL = start;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            
//             int l1val, l2val;
//             if(l1 == NULL) l1val = 0;
//             else l1val = l1->val;
            
//             if(l2 == NULL) l2val = 0;
//             else l2val = l2->val;
            
            
            //easy way to write
            
            int l1val = (l1!=NULL)? l1->val: 0;
            int l2val = (l2!=NULL)? l2->val: 0;
    
            int sum = l1val + l2val + carry;
            carry = sum/10;
            int digit = sum%10;
            
            ListNode *digi = new ListNode(digit);
            ourLL->next = digi;
            
            if(l1 != NULL) l1=l1->next;
            if(l2 != NULL) l2=l2->next;
