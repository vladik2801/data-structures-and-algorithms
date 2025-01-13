#include <iostream>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v, Node* n = nullptr) : val(v), next(n) {}
};

struct Stack {
    Node* head;
    Stack() : head(nullptr) {}

    void Push(long long value) {
        head = new Node(value, head);
    }

    long long Pop() {
        Node* temp = head;
        long long time_el = head->val;
        head = head->next;
        delete temp;
        return time_el;
    }
    long long GiveHead() const {
        if (head != nullptr) {
            return head->val;
        } else {
            return -1;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Stack ind, value;

    long long count_wood;
    cin >> count_wood;

    long long len_wood;
    long long max_sq = 0;

    ind.Push(0);
    value.Push(0);

    for (int i = 1; i <= count_wood + 1; ++i) {
        if (i <= count_wood) {
            cin >> len_wood;
        } else {
            len_wood = 0;
        }

        long long x = i;

        while (len_wood <= value.GiveHead()) {
            x = ind.GiveHead();
            long long H = value.GiveHead();
            ind.Pop();
            value.Pop();
            long long s_count = H * (i - x);
            if (s_count > max_sq) {
                max_sq = s_count;
            }
        }

        if (len_wood > value.GiveHead()) {
            ind.Push(x);
            value.Push(len_wood);
        }
    }

    cout << max_sq << endl;
    return 0;
}
