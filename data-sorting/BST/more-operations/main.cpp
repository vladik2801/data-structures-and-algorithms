#include <iostream>
using namespace std;

struct BinNode {
    int data;
    BinNode* left;
    BinNode* right;
    BinNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

BinNode* push(BinNode* root, int value) {
    BinNode* parent = nullptr;
    BinNode* current = root;

    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return root;
        }
    }

    BinNode* newNode = new BinNode(value);
    if (parent == nullptr) {
        return newNode;
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return root;
}

BinNode* findMin(BinNode* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

BinNode* deleteNode(BinNode* root, int value) {
    BinNode* parent = nullptr;
    BinNode* current = root;

    while (current != nullptr && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) return root;

    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr) {
            delete current;
            return nullptr;
        }
        if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    } else if (current->left == nullptr) {
        if (parent == nullptr) {
            BinNode* temp = current->right;
            delete current;
            return temp;
        }
        if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    } else if (current->right == nullptr) {
        if (parent == nullptr) {
            BinNode* temp = current->left;
            delete current;
            return temp;
        }
        if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    } else {
        BinNode* minRight = findMin(current->right);
        current->data = minRight->data;
        current->right = deleteNode(current->right, minRight->data);
    }
    return root;
}

bool search(BinNode* root, int value) {
    while (root != nullptr) {
        if (root->data == value) return true;
        root = (value < root->data) ? root->left : root->right;
    }
    return false;
}

BinNode* findMinGreaterThan(BinNode* root, int x) {
    BinNode* result = nullptr;
    while (root != nullptr) {
        if (root->data > x) {
            result = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return result;
}

BinNode* findMaxLessThan(BinNode* root, int x) {
    BinNode* result = nullptr;
    while (root != nullptr) {
        if (root->data < x) {
            result = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    BinNode* root = nullptr;
    int operation, value;

    while (cin >> operation >> value) {
        if (operation == 0) {
            root = push(root, value);
        } else if (operation == 1) {
            root = deleteNode(root, value);
        } else if (operation == 2) {
            if (search(root, value)) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        } else if (operation == 3) {
            BinNode* minGreater = findMinGreaterThan(root, value);
            if (minGreater) {
                cout << minGreater->data << "\n";
            } else {
                cout << "none\n";
            }
        } else if (operation == 4) {
            BinNode* maxLess = findMaxLessThan(root, value);
            if (maxLess) {
                cout << maxLess->data << "\n";
            } else {
                cout << "none\n";
            }
        }
    }

    return 0;
}
