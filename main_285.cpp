#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    TreeNode *res = nullptr;
    stack<TreeNode *> stk;
    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (!res && (!stk.empty() || cur)) {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        if (pre == p) {
            res = cur;
        } else {
            pre = cur;
            cur = cur->right;
        }
    }
    return res;
}