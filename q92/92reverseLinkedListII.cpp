#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        ListNode* p = head;
        ListNode* h1 = NULL;
        ListNode* l1 = NULL;
        ListNode* h2 = NULL;
        ListNode* l2 = NULL;

        int cnt = 0;
        while(cnt < n){
            cnt += 1;
            if (cnt == m-1){ //3
                h1 = p;
                l1 = p->next;
            }
            if (cnt == n-1){ //4
                h2 = p;
                l2 = p->next;
            }
            p = p->next;
        }

        ListNode* tmp = NULL;
        tmp = l2->next;

        if(h2 == l1){
            h1->next = l2;
            l2->next = l1;
            l1->next = tmp;
        }
        else{
            h1->next = l2;
            l2->next = l1->next;

            h2->next = l1;
            l1->next = tmp;
        }

        return head;
    }
};

void push(ListNode* node, int val){
    ListNode* p = new ListNode(val);
    while(node->next != NULL){
        node = node->next;
    }
    node->next = p;
}

void printList(ListNode* node){
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    push(head, 7);

    int m = 4;
    int n = 5;

    ListNode* result = s.reverseBetween(head, m, n);
    printList(result);

    return 0;
}