## ACM模式的手撕二叉树

0. 手写二叉树结构体

1. 根据给定序列构建二叉树
2. 根据二叉树打印序列

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(val), left(left), right(right) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* build(vector<int>& tree) {
    int n = tree.size();
    vector<TreeNode*> build_tree(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (tree[i] == -1) continue;
        TreeNode* tmp = new TreeNode(tree[i]);
        build_tree[i] = tmp;
    }
    for (int i = 0; i * 2 + 2 < n; ++i) {
        if (!build_tree[i]) continue;
        build_tree[i]->left = build_tree[i * 2 + 1];
        build_tree[i]->right = build_tree[i * 2 + 2];
    }
    return build_tree[0];
}

void preorder_print(TreeNode* root) {
    if (!root) {
        cout << "NULL" << " ";
        return;
    }
    cout << root->val << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

void inorder_print(TreeNode* root) {
    if (!root) {
        cout << "NULL" << " ";
        return;
    }
    inorder_print(root->left);
    cout << root->val << " ";
    inorder_print(root->right);
}

void postorder_print(TreeNode* root) {
    if (!root) {
        cout << "NULL" << " ";
        return;
    }
    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->val << " ";
}

vector<int> print_seq(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp) {
            ans.push_back(tmp->val);
            q.push(tmp->left);
            q.push(tmp->right);
        }
        else ans.push_back(-1);
    }
    return ans;
}

int main() {
    vector<int> tree_seq({4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8});
    cout << "原始序列：";
    for (int i : tree_seq) cout << i << " ";
    cout << endl;
    // 给定层序遍历数组，输出二叉树
    TreeNode* root = build(tree_seq);
    // 给定二叉树，前中后序遍历
    cout << "前序遍历：";
    preorder_print(root);
    cout << endl;
    cout << "中序遍历：";
    inorder_print(root);
    cout << endl;
    cout << "后序遍历：";
    postorder_print(root);
    cout << endl;
    // 给定二叉树，层序输出数组
    vector<int> build_seq = print_seq(root);
    cout << "重构序列：";
    for (int i = 0; i < build_seq.size(); ++i) cout << build_seq[i] << " ";
    cout << endl;

    return 0;
}
```

