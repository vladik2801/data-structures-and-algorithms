#include <iostream>
using namespace std;

struct BinNode {
    int data;
    BinNode* left;
    BinNode* right;
    BinNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
BinNode* push(BinNode* root, int value) {
    if (root == nullptr) {
        BinNode* newNode = new BinNode(value);
        root = newNode;
        return root;
    }
    if (value < root->data) {
        root->left = push(root->left, value);
    }
    else {
        root->right = push(root->right, value);
    }
    return root;
}
void Print(BinNode* node) {
    if (node == nullptr) {
        return;
    }
    Print(node->left);
    cout << node->data << " ";
    Print(node->right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    BinNode *root = nullptr;
    int count_nodes;
    cin >> count_nodes;
    for (int i = 0; i < count_nodes; i++) {
        int value;
        cin >> value;
        root = push(root, value);
    }
    Print(root);
    return 0;
}
