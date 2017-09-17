//******************************************************************************
//method1: this method recursive call the mergeTwoLists, but this method costs
//         too much time.
//******************************************************************************
// #include <iostream>
// #include <vector>
// #include <stdlib.h>
// #include <limits.h>

// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// public:
//     //convert mergeKLists to mergeTwoLists recursivly
//     ListNode* mergeKLists(vector<ListNode*>& lists){
//         ListNode* result = NULL;
//         for(int i = 0; i < lists.size(); ++i){
//             result = mergeTwoLists(result, lists[i]);
//         }

//         return result;
//     }

//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
//         ListNode* result = new ListNode(-1);
//         ListNode* tmp = result;
//         while(l1 and l2){
//             if(l1->val < l2->val){
//                 cout << "a: " << endl;
//                 tmp->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 cout << "b: " << endl;
//                 tmp->next = l2;
//                 l2 = l2->next;
//             }
//             tmp = tmp->next;
//         }
//         if(l1 == NULL){
//             cout << "c: " << endl;
//             tmp->next = l2;
//         }
//         if(l2 == NULL){
//             cout << "d: " << endl;
//             tmp->next = l1;
//         }
//         // printList(result->next);
//         return result->next;
//     }

//     void printList(ListNode* node){
//         while(node!=NULL){
//             cout << node->val << " ";
//             node = node->next;
//         }
//         cout << endl;
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
//     while(node!=NULL){
//         cout << node->val << " ";
//         node = node->next;
//     }
//     cout << endl;
// }

// int main(){
//     Solution s;
//     vector<ListNode*> lists;
//     //get k lists
//     int k = 5;
//     for(int i = 0; i < k; ++i){
//         int val = rand()%20;
//         int l = rand()%5;
//         ListNode* p = new ListNode(val);
//         for (int j = 0; j < l; ++j){
//             push(p, val+3*(j+1));
//         }
//         printList(p);
//         lists.push_back(p);
//     }

//     //merge k lists
//     ListNode* result = s.mergeKLists(lists);
//     printList(result);

//     return 0;
// }
//
//==============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class cmp{
public:
    bool operator()(ListNode* p1, ListNode* p2) const {
        return p1->val > p2->val;
    }
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* result = new ListNode(-1);
        int len = lists.size();

        ListNode* p = result;
        while(!lists.empty()){
            make_heap(lists.begin(), lists.end(), cmp()); //small top heap

            p->next = lists.front();
            p = p->next;

            pop_heap(lists.begin(), lists.end(), cmp());
            lists.pop_back();

            if(p->next != NULL){
                lists.push_back(p->next);
            }
        }
        return result->next;
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
    while(node!=NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}


int main(){
    Solution s;
    vector<ListNode*> lists;

    //get k lists
    int k = 5;
    for(int i = 0; i < k; ++i){
        int val = rand()%20;
        int l = rand()%5;
        ListNode* p = new ListNode(val);
        for (int j = 0; j < l; ++j){
            push(p, val+3*(j+1));
        }
        printList(p);
        lists.push_back(p);
    }

    //merge k lists
    ListNode* result = s.mergeKLists(lists);
    printList(result);

    return 0;
}