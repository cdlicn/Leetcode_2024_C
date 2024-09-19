#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode;
    ListNode *node = head;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    if (list1) {
        node->next = list1;
    }
    if (list2) {
        node->next = list2;
    }
    return head->next;
}