#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pre = -9999;

ListNode *deleteDuplicates(ListNode *head) {
    if(!head) {
        return nullptr;
    }
    if (head->val == pre) {
        return deleteDuplicates(head->next);
    } else {
        pre = head->val;
        head->next = deleteDuplicates(head->next);
        return head;
    }
}