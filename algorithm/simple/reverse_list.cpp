
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

ListNode* reverseList(ListNode* head) {
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = nullptr;

    while(cur){
        // store next node
        temp = cur->next;
        // reverse
        cur->next = pre;
        // update pre and cur
        pre = cur;
        cur = temp;
    }
    return pre;
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

void deleteListNode(ListNode*& p)
{
    if(!p) return;
    while(p){
        ListNode* q = p;
        p = p->next;
        delete q;
    }
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

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int val = 2;
    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    ListNode* p = generateListNode(v);
    printList(p);
    ListNode* cur = reverseList(p);
    printList(cur);
    deleteListNode(p);

    return 0;
}

/**
 * @result
 * 
 *  0 1 2 2 4 2 6
    0 1 4 6
 */