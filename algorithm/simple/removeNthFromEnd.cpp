
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
    ListNode* cur = removeNthFromEnd(p, val);
    printList(cur);
    deleteListNode(p);

    return 0;
}

/**
 * @result
 * 

 */