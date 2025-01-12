#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct Stack {
    Node* head = nullptr;

    bool IsEmpty() {
        return head == nullptr;
    }

    void Push(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void Pop() {
        if (IsEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack spis;
    int count_operation;
    cin >> count_operation;

    string output;
    for (int i = 0; i < count_operation; i++) {
        char operation;
        cin >> operation;

        if (operation == '+') {
            int op;
            cin >> op;
            spis.Push(op);
        } else if (operation == '-') {
            output += to_string(spis.head->data) + "\n";
            spis.Pop();
        }
    }

    cout << output;
    return 0;
}
