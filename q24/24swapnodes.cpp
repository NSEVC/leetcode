//******************************************************************************
// method1: change the nodes in pairs
//******************************************************************************
// #include <iostream>

// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution{
// public:
//     ListNode* swapNodesInPairs(ListNode* head){
//         ListNode* first = new ListNode(-1);
//         ListNode* third = head->next;
//         ListNode* p = first;
//         ListNode* tmp = NULL;
//         while(head!=NULL and third!=NULL){
//             first->next = third;
//             tmp = third->next;
//             third->next = head;
//             first = head;
//             head = tmp;
//             if(tmp!=NULL) {third = tmp->next;}
//             else {third = NULL;}
//         }
//         first->next = head;

//         return p->next;
//     }
// };

// void push(ListNode* head, int val){
//     ListNode* p = new ListNode(val);
//     while(head->next != NULL){
//         head = head->next;
//     }
//     head->next = p;
// }

// void printList(ListNode* head){
//     while(head){
//         cout << head->val << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main(){
//     Solution s;
//     ListNode* head = new ListNode(1);
//     push(head, 2);
//     push(head, 3);
//     push(head, 4);
//     push(head, 5);
//     push(head, 6);
//     printList(head);

//     ListNode* result = s.swapNodesInPairs(head);
//     printList(result);

//     return 0;
// }

//==============================================================================

//******************************************************************************
// method2: change the node's value in pairs
//******************************************************************************
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* swapNodesInPairs(ListNode* head){
        ListNode* p = head;
        int tmp;
        while(head && head->next){
            tmp = head->val;
            head->val = head->next->val;
            head->next->val = tmp;
            head = head->next->next;
        }
        return p;
    }
};

void push(ListNode* head, int val){
    ListNode* p = new ListNode(val);
    while(head->next){
        head = head->next;
    }
    head->next = p;
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
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

    ListNode* result = s.swapNodesInPairs(head);
    printList(result);

    return 0;
}