
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = l1.val + l2.val;
        int cr = sum / 10;

        ListNode resultList = new ListNode(sum % 10);
        ListNode tempRes = resultList;

        ListNode temp1 = l1.next;
        ListNode temp2 = l2.next;

        while (temp1 != null || temp2 != null) {
            sum = 0;

            if (temp1 != null) {
                sum = sum + temp1.val;
                temp1 = temp1.next;
            }

            if (temp2 != null) {
                sum = temp2.val + sum;
                temp2 = temp2.next;
            }

            sum = sum + cr;
            cr = sum / 10;
            sum = sum % 10;

            tempRes.next = new ListNode(sum);
            tempRes = tempRes.next;
        }

        if (cr != 0) {
            tempRes.next = new ListNode(cr);
        }

        return resultList;

    }
}

// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}