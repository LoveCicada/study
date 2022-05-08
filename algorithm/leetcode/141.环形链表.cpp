/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            // slow node move one step forward
            slow = slow->next;
            // fast node move two step forward
            fast = fast->next->next;
            
            // when fast meet slow, the list exist circle 
            if(fast == slow){
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

