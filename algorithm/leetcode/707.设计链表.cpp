/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    // 定义链表节点的结构体
    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int val) : val(val), next(nullptr){}
    };

    MyLinkedList() {
        m_pList = new LinkNode(0);
        m_nListLength = 0;
    }
    
    int get(int index) {
        if(index > (m_nListLength - 1) || index < 0){
            return -1;
        }

        LinkNode* p = m_pList->next;
        while(index--){
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        LinkNode* p = new LinkNode(val);
        p->next = m_pList->next;
        m_pList->next = p;
        m_nListLength++;
    }
    
    void addAtTail(int val) {
        LinkNode* p = new LinkNode(val);
        LinkNode* cur = m_pList;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = p;
        m_nListLength++;
    }
    
    void addAtIndex(int index, int val) {
        if( index > m_nListLength){
            return;
        }

        LinkNode* p = new LinkNode(val);
        LinkNode* cur = m_pList;
        while(index--){
            cur = cur->next;
        }
        p->next = cur->next;
        cur->next = p;
        m_nListLength++;
    }
    
    void deleteAtIndex(int index) {
        if( index >= m_nListLength || index < 0){
            return;
        }

        LinkNode* cur = m_pList;
        while(index--){
            cur = cur->next;
        }
        LinkNode* p = cur->next;
        cur->next = cur->next->next;
        delete p;
        m_nListLength--;
    }

    void printList(){
        LinkNode* cur = m_pList;
        while(cur->next != nullptr){
            cout << cur->next->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int m_nListLength;
    LinkNode* m_pList;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

