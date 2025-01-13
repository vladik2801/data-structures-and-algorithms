#include <iostream>
using namespace std;

struct Node {
    long value;
    Node* left;
    Node* right;

    Node(long val) : value(val), left(nullptr), right(nullptr) {}

    Node* Push(Node* root, long x) {
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

    void find(Node* root, long level, long& initial_lvl) {
        if (!root) return;

        if (level > initial_lvl) {
            cout << root->value << " ";
            initial_lvl = level;
        }

        find(root->right, level + 1, initial_lvl);
        find(root->left, level + 1, initial_lvl);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;
    long n;
    cin >> n;

    for (long i = 0; i < n; ++i) {
        long x;
        cin >> x;

        if (root == nullptr) {
            root = new Node(x);
        } else {
            root = root->Push(root, x);
        }
    }

    long initial_lvl = -1;
    root->find(root, 0, initial_lvl);

    return 0;
}
