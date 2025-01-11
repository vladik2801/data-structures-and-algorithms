#include <iostream>

using namespace std;

void Quicksort(long long arr[], int left, int right){
    if (left >= right) return;
    int pivot = (arr[left] + arr[right]) / 2;
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    Quicksort(arr, left, j);
    Quicksort(arr, i, right);
}


int main() {
    int count_branches;
    cin>>count_branches;
    if (count_branches < 4) {}
    long long* massive_branches = new long long[count_branches];
    for(int i=0;i<count_branches;i++) {
        cin>>massive_branches[i];
    }
    Quicksort(massive_branches, 0, count_branches-1);
    long long sum_square = 0;
    long side1 = 0;
    long side2 = 0;
    for (int i = count_branches-1; i >= 1; i--) {
        if (massive_branches[i] == massive_branches[i-1] ) {
            if (side1 == 0) {
                side1 = massive_branches[i];
                i--;
            }
            else if (side2 == 0) {
                side2 = massive_branches[i];
                i--;
            }
        }
        else if (massive_branches[i] - 1 == massive_branches[i-1] ) {
            if (side1 == 0) {
                side1 = massive_branches[i]-1;
                i--;
            }
            else if (side2 == 0) {
                side2 = massive_branches[i]-1 ;
                i--;
            }
        }
        if (side1!=0 && side2!=0) {
            sum_square += side1 * side2;
            side1 = 0;
            side2 = 0;

        }
    }
    
    cout<<sum_square;
    delete[] massive_branches;
    return 0;
}
