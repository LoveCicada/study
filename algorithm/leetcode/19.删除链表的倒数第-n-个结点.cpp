/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualHead = new ListNode(0);
        virtualHead->next = head;
        ListNode* slow = virtualHead;
        ListNode* fast = virtualHead;

        while(n-- && fast != nullptr) {
            fast = fast->next;
        }

        fast = fast->next;
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        //delete slow->next;
        ListNode* pD = slow->next;
        slow->next = slow->next->next;
        delete pD;

        ListNode* p = virtualHead->next;
        delete virtualHead;
        return p;
    }
};
// @lc code=end

