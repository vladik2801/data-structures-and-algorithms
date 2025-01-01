#include <iostream>


void Quicksort(int arr[], int l, int r) {
    if (l>=r) return;
    int pivot = (arr[l]+arr[r])/2;
    int i = l;
    int j = r;
    while (i<=j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i<=j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }
    Quicksort(arr,l,j);
    Quicksort(arr,i,r);
}


int main() {
    int count_patinson;
    std::cin>>count_patinson;
    int* massive_patinson = new int[count_patinson];
    for(int i=0;i<count_patinson;i++) {
        std::cin>>massive_patinson[i];
    }
    Quicksort(massive_patinson, 0, count_patinson-1);

    for (int i = 0; i < count_patinson; i++) {
        std::cout<<massive_patinson[i]<<" ";
    };
    delete[] massive_patinson;
    return 0;
}
