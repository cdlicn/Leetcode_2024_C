#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *node, TreeNode *subRoot) {
    if (!node && !subRoot) {
        return true;
    }
    if (!node || !subRoot) {
        return false;
    }
    if (node->val != subRoot->val) {
        return false;
    }
    return dfs(node->left, subRoot->left) && dfs(node->right, subRoot->right);
};

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (dfs(node, subRoot)) {
            return true;
        }
        if (node->left) {
            q.emplace(node->left);
        }
        if (node->right) {
            q.emplace(node->right);
        }
    }
    return false;
}