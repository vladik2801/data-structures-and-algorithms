#include <iostream>

using namespace std;

void QuickSort(int arr[], int l, int r, int count_max) {
    if (l>=r) return;
    int pivot = arr[r];
    int i = l;
    int j = r;
    while (i<=j) {
        while (arr[i] > pivot) {
            i++;
        }
        while (arr[j] < pivot) {
            j--;
        }
        if (i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }
    if (l < j && j >= count_max - 1) {
        QuickSort(arr,l,j,count_max);
    }
    if (i < r && i < count_max) {
        QuickSort(arr,i,r,count_max);
    }
}

int main() {
    int count_day, count_max;
    cin >> count_day >> count_max;

    int A, B, C, day1, day2;
    cin >> A >> B >> C >> day1 >> day2;
    int* stats = new int[count_day];

    stats[0] = day1;
    stats[1] = day2;
    for (int i = 2; i < count_day; ++i) {
        stats[i] = (stats[i - 2] * A + stats[i - 1] * B + C);
    }

    QuickSort(stats, 0, count_day - 1, count_max);
    int result = 0;

    for (int i = 0; i < count_max; ++i) {
        result ^= stats[i];
    }

    cout << result << endl;
    delete[] stats;

    return 0;
}
