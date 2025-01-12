#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int a) : value(a), next(nullptr), prev(nullptr) {}
};

struct Queue {
    Node* head;
    Node* tail;

    Queue() : head(nullptr), tail(nullptr) {}

    void push(int a) {
        Node* newNode = new Node(a);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int pop() {
        if (head == nullptr) return -1;
        int value = head->value;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return value;
    }

    int top() {
        if (head != nullptr) return head->value;
        return -1;  
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue queue;
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            queue.push(x);
        } else if (c == '-') {
            cout << queue.top() << "\n";
            queue.pop();
        }
    }
    return 0;
}
