#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeNodes(ListNode *head) {
    ListNode *root = head;
    for (ListNode *node = head->next; node->next; node = node->next) {
        if (node->val) {
            root->val += node->val;
        } else {
            root = root->next;
            root->val = 0;
        }
    }
    root->next = nullptr;
    return head;
}