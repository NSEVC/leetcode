//misunderstand the problem, what i do is change the loaction of two ListNode.
// #include <iostream>

// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int x):val(x), next(NULL) {}
// };

// class Solution{
// public:
//     ListNode* reverseBetween(ListNode* head, int m, int n){
//         ListNode* p = head;
//         ListNode* h1 = NULL;
//         ListNode* l1 = NULL;
//         ListNode* h2 = NULL;
//         ListNode* l2 = NULL;

//         int cnt = 0;
//         while(cnt < n){
//             cnt += 1;
//             if (cnt == m-1){
//                 h1 = p;
//                 l1 = p->next;
//             }
//             if (cnt == n-1){
//                 h2 = p;
//                 l2 = p->next;
//             }
//             p = p->next;
//         }

//         ListNode* tmp = NULL;
//         tmp = l2->next;

//         //eg:1->2->3->4->5->NULL, change the loaction of the 3 and 4
//         if(h2 == l1){
//             h1->next = l2;
//             l2->next = l1;
//             l1->next = tmp;
//         }
//         else{
//             h1->next = l2;
//             l2->next = l1->next;

//             h2->next = l1;
//             l1->next = tmp;
//         }

//         return head;
//     }
// };

// void push(ListNode* node, int val){
//     ListNode* p = new ListNode(val);
//     while(node->next != NULL){
//         node = node->next;
//     }
//     node->next = p;
// }

// void printList(ListNode* node){
//     while(node != NULL){
//         cout << node->val << " ";
//         node = node->next;
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
//     push(head, 7);

//     int m = 4;
//     int n = 5;

//     ListNode* result = s.reverseBetween(head, m, n);
//     printList(result);

//     return 0;
// }

//==============================================================================
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        int cnt = 0;
        ListNode* first_end = NULL;
        ListNode* first = NULL;
        ListNode* second = head;
        ListNode* third = NULL;
        while(cnt < n){
            cnt += 1;
            if(cnt == m-1){
                first_end = second;
                first = second;
                second = second->next;
            }
            else if(cnt>=m && cnt<=n){
                third = second->next;
                second->next = first;
                first = second;
                second = third;
            }
            else{
                second = second->next;
            }
        }

        if(first_end!=NULL){
            first_end->next->next = second;
            first_end->next = first;
        }
        else{
            head->next = second;
            head = first;
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
    push(head, 7);
    printList(head);

    int m = 1;
    int n = 5;

    ListNode* result = s.reverseBetween(head, m, n);
    printList(result);

    return 0;
}

