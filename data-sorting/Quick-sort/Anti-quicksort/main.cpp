#include <iostream>

void QuickSort(int arr[], int n) {
    for (int i = 2; i < n ; i++) {
        std::swap(arr[i], arr[i/2]);
    }
}

int main() {
    int n;
    std::cin>>n;
    int* massive_patinson = new int[n];
    for(int i=0;i<n;i++) {
        massive_patinson[i] = i+1;
    }

    QuickSort(massive_patinson,n);
    for (int i = 0; i < n; i++) {
        std::cout<<massive_patinson[i]<<" ";
    };
    delete[] massive_patinson;
    return 0;
}
