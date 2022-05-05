
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val){
    
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

ListNode* removeElements2(ListNode* head, int val){
    ListNode* virtualHead = new ListNode(0);
    virtualHead->next = head;
    ListNode* cur = virtualHead;
    while(cur->next != NULL){
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

ListNode* generateListNode(const vector<int>& v)
{
    if(v.size() <= 0){
        return NULL;
    }
    ListNode* p = NULL;
    ListNode* head = NULL;
    for(int i = 0; i < v.size(); i++){
        ListNode* q = new ListNode(v[i]);
        if(!p){
            p = q;
            head = p;
        }
        else{
            if(p->next != NULL){
                p = p->next;
            }
            p->next = q;
        }
    }

    return head;
}

void printList(ListNode* p)
{
    if(!p) return;
    while(p){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

void deleteListNode(ListNode*& p)
{
    if(!p) return;
    while(p){
        ListNode* q = p;
        p = p->next;
        delete q;
    }
}

int main()
{
    int array[] = {0, 1, 2, 2, 4, 2, 6};
    int val = 2;
    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    ListNode* p = generateListNode(v);
    printList(p);
    //removeElements(p, 2);
    removeElements2(p, 2);
    printList(p);
    deleteListNode(p);

    return 0;
}

/**
 * @result
 * 
 *  0 1 2 2 4 2 6
    0 1 4 6
 */