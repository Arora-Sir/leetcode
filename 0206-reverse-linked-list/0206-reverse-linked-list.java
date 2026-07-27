/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode curr = head;
        ListNode currNext = head.next;
        while(head!=null){
            if(curr==head) curr.next = null;
            else curr.next=head;
            head=curr;
            if(currNext==null) return head;
            curr=currNext;
            currNext=curr.next;
        }   
        return head;
    }
}