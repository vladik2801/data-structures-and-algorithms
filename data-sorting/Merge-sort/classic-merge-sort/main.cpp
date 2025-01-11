#include <iostream>

using namespace std;

void Merge(int arr[], int left, int mid, int right) {
    int count_first = mid - left + 1;
    int count_second = right - mid;

    int* Left_massive = new int[count_first];
    int* Right_massive = new int[count_second];

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
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

int main() {
    int count_elements;
    cin >> count_elements;

    int* arr = new int[count_elements];
    for (int i = 0; i < count_elements; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, 0, count_elements - 1);

    for (int i = 0; i < count_elements; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
