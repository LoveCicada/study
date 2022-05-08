/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            // slow move one step
            slow = slow->next;
            // fast move two step
            fast = fast->next->next;

            // when fast meet slow, the list exist circle
            if(fast == slow) {
                // the length between head and entry point 
                // equal to between meet point and entry point
                ListNode* idx1 = fast;
                ListNode* idx2 = head;
                while(idx1 != idx2) {
                    idx1 = idx1->next;
                    idx2 = idx2->next;
                }
                // return circle entry point
                return idx2;
            }
        }
        
        return NULL;
    }
};
// @lc code=end

