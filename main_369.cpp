struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *plusOne(ListNode *head) {
    ListNode *notNine = nullptr;
    ListNode *cur = head;
    while (cur) {
        if (cur->val != 9) {
            notNine = cur;
        }
        cur = cur->next;
    }
    if (notNine) {
        notNine->val += 1;
        notNine = notNine->next;
    } else {
        notNine = head;
    }
    while (notNine) {
        notNine->val = 0;
        notNine = notNine->next;
    }
    if (head->val == 0) {
        ListNode *h = new ListNode(1);
        h->next = head;
        return h;
    }
    return head;
}