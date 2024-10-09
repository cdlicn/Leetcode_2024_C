#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA;
    ListNode *nodeB = headB;
    while (nodeA != nodeB) {
        nodeA = nodeA ? nodeA->next : headB;
        nodeB = nodeB ? nodeB->next : headA;
    }
    return nodeA;
}