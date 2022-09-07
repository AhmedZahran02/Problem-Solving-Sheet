class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "", s2 = "";
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while (ptr1) {
            s1 += to_string(ptr1->val);
            ptr1 = ptr1->next;
        }
        while (ptr2) {
            s2 += to_string(ptr2->val);
            ptr2 = ptr2->next;
        }
        int diff = s1.length() - s2.length();
        for (int i = 0; i < diff; i++) {
            s2 += '0';
        }
        int diff2 = s2.length() - s1.length();
        for (int i = 0; i < diff2; i++) {
            s1 += '0';
        }
        ListNode* l3 = new ListNode();
        ListNode* ptr3 = l3;
        int carry = 0;
        for (int i = 0; i < s1.length(); i++) {
            int sum = (s1[i] - '0' + s2[i] - '0' + carry) % 10;
            carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
            ptr3->val = sum;
            if (i == s1.length() - 1)
            {
                if (carry != 0)
                {
                    ptr3->next = new ListNode(carry);
                }
            }
            else
            {
                ptr3->next = new ListNode();
            }
            ptr3 = ptr3->next;
        }
        if (carry == 0)
        {
            ptr3 = nullptr;
        }
        else
        {
            ptr3->val = carry;
        }
        return l3;
    }
};