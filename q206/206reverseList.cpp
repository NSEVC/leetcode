#include <iostream>

using namespace std;

struct  ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* first = NULL;
        ListNode* third = NULL;
        while(head)
        {
            third = head->next;
            head->next = first;
            first = head;
            head = third;
        }
        return first;
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
    while(node){
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
    printList(head);

    ListNode* result = s.reverseList(head);
    printList(result);

    return 0;

}