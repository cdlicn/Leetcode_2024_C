#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int more = 0;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) {
        if (more) {
            return new ListNode(1);
        }
        return nullptr;
    }
    if (!l1) {
        l1 = l2;
        l2 = nullptr;
    }
    l1->val = l1->val + (l2 ? l2->val : 0) + more;
    more = l1->val / 10;
    l1->val = l1->val % 10;
    l1->next = addTwoNumbers(l1->next, l2 ? l2->next : l2);
    return l1;
}