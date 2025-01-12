#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoubleList {
    Node* head;
    Node* tail;

    DoubleList() : head(nullptr), tail(nullptr) {}

    void Push(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};


bool IsPlace(Node* head, int count_people, int distance) {
    int count = 1;
    int last_position = head->data;
    Node* current = head->next;

    while (current) {
        if (current->data - last_position >= distance) {
            count++;
            last_position = current->data;
            if (count == count_people) return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    int count_places, count_people;
    cin >> count_places >> count_people;

    DoubleList list;
    for (int i = 0; i < count_places; ++i) {
        int chair;
        cin >> chair;
        list.Push(chair);
    }

    int left = 0;
    int right = list.tail->data - list.head->data;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (IsPlace(list.head, count_people, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
