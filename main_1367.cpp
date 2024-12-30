#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(ListNode *node, TreeNode *root) {
    if (!node) {
        return true;
    }
    if (!root) {
        return false;
    }
    if (node->val != root->val) {
        return false;
    }
    return dfs(node->next, root->left) || dfs(node->next, root->right);
}

bool isSubPath(ListNode *head, TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *treeNode = q.front();
        q.pop();
        if (treeNode->val == head->val && dfs(head, treeNode)) {
            return true;
        }
        if (treeNode->left) {
            q.push(treeNode->left);
        }
        if (treeNode->right) {
            q.push(treeNode->right);
        }
    }
    return false;
}

