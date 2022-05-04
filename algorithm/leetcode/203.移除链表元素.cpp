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
        // 删除头节点
        while(head != NULL && head->val == val){
            ListNode *p = head;
            head = head->next;
            delete p;
        }

        // 删除非头节点
        ListNode* pCur = head;
        while(pCur != NULL && pCur->next != NULL){
            if(pCur->next->val == val){
                // 删除下一个节点
                ListNode *q = pCur->next;
                pCur->next = pCur->next->next;
                delete q;
            }else{
                pCur = pCur->next;
            }
        }

        return head;
    }
};
// @lc code=end

