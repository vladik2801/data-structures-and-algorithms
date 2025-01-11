#include <iostream>

using namespace std;

long long Merge(long long arr[], int left, int mid, int right) {
    int count_first = mid - left + 1;
    int count_second = right - mid;
    long long count_error = 0;

    long long* Left_massive = new long long[count_first];
    long long* Right_massive = new long long[count_second];

    for (int i = 0; i < count_first; i++)
        Left_massive[i] = arr[left + i];
    for (int j = 0; j < count_second; j++)
        Right_massive[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < count_first && j < count_second) {
        if (Left_massive[i] <= Right_massive[j]) {
            arr[k] = Left_massive[i];
            i++;
        } else {
            arr[k] = Right_massive[j];
            count_error += (count_first - i); // Считаем количество инверсий
            j++;
        }
        k++;
    }

    while (i < count_first) {
        arr[k] = Left_massive[i];
        i++;
        k++;
    }
    while (j < count_second) {
        arr[k] = Right_massive[j];
        j++;
        k++;
    }

    delete[] Left_massive;
    delete[] Right_massive;

    return count_error;
}

long long MergeSort(long long arr[], int left, int right) {
    long long count_error = 0;
    if (left < right) {
        int middle = left + (right - left) / 2;
        count_error += MergeSort(arr, left, middle);
        count_error += MergeSort(arr, middle + 1, right);
        count_error += Merge(arr, left, middle, right);
    }
    return count_error;
}

int main() {
    int count_students;
    cin >> count_students;

    long long* massive_statist = new long long[count_students];
    for (int i = 0; i < count_students; i++) {
        cin >> massive_statist[i];
    }

    long long count_pairs = MergeSort(massive_statist, 0, count_students - 1);
    cout << count_pairs << endl;

    delete[] massive_statist;
    return 0;
}
