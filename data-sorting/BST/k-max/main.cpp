#include <iostream>
using namespace std;

struct BinNode {
    int data;
    int size;
    BinNode* left;
    BinNode* right;

    BinNode(int value) : data(value), size(1), left(nullptr), right(nullptr) {}
};

BinNode* Push(BinNode* root, int value) {
    if (root == nullptr) {
        return new BinNode(value);
    }
    if (value < root->data) {
        root->left = Push(root->left, value);
    } else {
        root->right = Push(root->right, value);
    }
    root->size = 1;
    if (root->left != nullptr) {
        root->size += root->left->size;
    }
    if (root->right != nullptr) {
        root->size += root->right->size;
    }
    return root;
}

BinNode* minim(BinNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

BinNode* Pop(BinNode* root, int value) {
    if (value < root->data) {
        root->left = Pop(root->left, value);
    } else if (value > root->data) {
        root->right = Pop(root->right, value);
    } else {
        if (root->left == nullptr) {
            BinNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinNode* temp = root->left;
            delete root;
            return temp;
        }
        BinNode* temp = minim(root->right);
        root->data = temp->data;
        root->right = Pop(root->right, temp->data);
    }
    root->size = 1;
    if (root->left != nullptr) {
        root->size += root->left->size;
    }
    if (root->right != nullptr) {
        root->size += root->right->size;
    }
    return root;
}

int findKthMax(BinNode* root, int k) {
    int rightSize = 0;
    if (root->right != nullptr) {
        rightSize = root->right->size;
    }

    if (k <= rightSize) {
        return findKthMax(root->right, k);
    } else if (k == rightSize + 1) {
        return root->data;
    } else {
        return findKthMax(root->left, k - rightSize - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BinNode* root = nullptr;
    int operation;
    cin >> operation;

    for (int i = 0; i < operation; i++) {
        int option, value;
        cin >> option;

        if (option == 1) {
            cin >> value;
            root = Push(root, value);
        }
        else if (option == 0) {
            cin >> value;
            cout << findKthMax(root, value) << "\n";
        }
        else if (option == -1) {
            cin >> value;
            root = Pop(root, value);
        }
    }

    return 0;
}
