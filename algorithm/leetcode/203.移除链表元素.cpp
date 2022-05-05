/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* virtualHead = new ListNode(0);
        virtualHead->next = head;
        ListNode* cur = virtualHead;
        while(cur->next != NULL) {
            if(cur->next->val == val){
                ListNode* p = cur->next;
                cur->next = cur->next->next;
                delete p;
            }else{
                cur = cur->next;
            }
        }

        head = virtualHead->next;
        delete virtualHead;
        return head;
    }
};
// @lc code=end

