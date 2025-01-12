#include <iostream>
#include <string>
using namespace std;

void merge(string* massive, int left, int mid, int right, int i) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string* L = new string[n1];
    string* R = new string[n2];

    for (int j = 0; j < n1; j++)
        L[j] = massive[left + j];
    for (int j = 0; j < n2; j++)
        R[j] = massive[mid + 1 + j];

    int k = left, l = 0, m = 0;

    while (l < n1 && m < n2) {
        if (L[l][L[l].length() - 1 - i] <= R[m][R[m].length() - 1 - i]) {
            massive[k++] = L[l++];
        } else {
            massive[k++] = R[m++];
        }
    }

    while (l < n1) {
        massive[k++] = L[l++];
    }

    while (m < n2) {
        massive[k++] = R[m++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(string* massive, int left, int right, int i) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(massive, left, mid, i);
        mergeSort(massive, mid + 1, right, i);
        merge(massive, left, mid, right, i);
    }
}

void Radix(string* massive, int len, int read) {
    for (int i = 0; i < read; i++) {
        mergeSort(massive, 0, len - 1, i);
    }
    for (int j = 0; j < len; j++) {
        cout << massive[j] << endl;
    }
}

int main() {
    int count_message;
    cin >> count_message;
    int long_message;
    cin >> long_message;
    int read_letters;
    cin >> read_letters;

    string* massive = new string[count_message];

    for (int i = 0; i < count_message; i++) {
        cin >> massive[i];
    }

    Radix(massive, count_message, read_letters);

    delete[] massive;

    return 0;
}
