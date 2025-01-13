#include <iostream>
using namespace std;

struct Node {
    long value;
    Node* left;
    Node* right;
    Node(long val) : value(val), left(nullptr), right(nullptr) {}
};


Node* Push(Node* root, int x) {
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root->value) {
        root->left = Push(root->left, x);
    } else if (x > root->value) {
        root->right = Push(root->right, x);
    }
    return root;
}


long getMaxHeight(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(getMaxHeight(root->left), getMaxHeight(root->right));
}


long getMinHeight(Node* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1;
    }

    if (!root->left) {
        return 1 + getMinHeight(root->right);
    }

    if (!root->right) {
        return 1 + getMinHeight(root->left);
    }

    return 1 + min(getMinHeight(root->left), getMinHeight(root->right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = Push(root, x);
    }

    int maxHeight = getMaxHeight(root);
    int minHeight = getMinHeight(root);

    cout << (maxHeight - minHeight) << endl;

    return 0;
}
