#include <iostream>
using namespace std;

struct Stack {
    int* data;
    int top;
    int capacity;

    Stack(long size) {
        data = new int[size];
        top = -1;
        capacity = size;
    }

    void push(long value) {
        if (top + 1 < capacity) {
            data[++top] = value;
        }
    }
    void pop() {
        if (top >= 0) {
            --top;
        }
    }

    long get(){
        if (top >= 0) {
            return data[top];
        }
        return -1;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

long countWater(int* heights, int n) {
    Stack stack(n);
    int water = 0;

    for (int i = 0; i < n; ++i) {

        while (!stack.isEmpty() && heights[i] > heights[stack.get()]) {
            int topIndex = stack.get();
            stack.pop();

            if (stack.isEmpty()) {
                break;
            }

            int leftIndex = stack.get();
            int width = i - leftIndex - 1;
            int height = min(heights[leftIndex], heights[i]) - heights[topIndex];
            water += width * height;
        }

        stack.push(i);
    }

    return water;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int width;
    cin >> width;

    int* heights = new int[width];
    for (long i = 0; i < width; ++i) {
        cin >> heights[i];
    }

    cout << countWater(heights, width) << endl;

    delete[] heights;
    return 0;
}
