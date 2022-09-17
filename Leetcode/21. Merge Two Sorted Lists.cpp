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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
        {
            return list2;
        }
        if (!list2)
        {
            return list1;
        }

        ListNode* ptr1;
        ListNode* ptr2;
        if (list1->val < list2->val)
        {
            ptr1 = list1;
            ptr2 = list2;
        }
        else
        {
            ptr1 = list2;
            ptr2 = list1;
        }
        ListNode* head = ptr1;
        ListNode* temp;
        while (ptr2)
        {
            if (!ptr1->next || ptr2->val < ptr1->next->val)
            {
                temp = ptr2->next;
                ptr2->next = ptr1->next;
                ptr1->next = ptr2;
                ptr2 = temp;
            }
            ptr1 = ptr1->next;
        }
        return head;
    }
};