#include <iostream>

using namespace std;

void Quicksort(pair<int, int> arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    pair<int, int> middle = arr[(left+right)/2];
    int i = left, j = right;
    while (i <= j) {
        while(arr[i]<middle) {
            i++;
        }
        while(arr[j]>middle) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    Quicksort(arr,left,j);
    Quicksort(arr,i,right);
}

int main() {
    int count_friend;
    cin>>count_friend;
    pair <int,int> zabor[count_friend];
    for (int i = 0; i < count_friend; i++) {
        int start,end;
        cin>>start>>end;
        zabor[i] = {start,end};
    }
    Quicksort(zabor, 0 ,count_friend - 1);
    int count_paint = 0;
    for (int i = 0; i < count_friend - 1; i++) {
        if (zabor[i].second >= zabor[i+1].first) {
            zabor[i + 1].first = min(zabor[i].first, zabor[i+1].first);
            zabor[i + 1].second = max(zabor[i].second, zabor[i+1].second);
            zabor[i] = {0,0};
        }
    }
    for (int i = 0; i < count_friend; i++) {
        if (zabor[i].first != 0 && zabor[i].second != 0) {
            count_paint += zabor[i].second - zabor[i].first + 1;
        }
    }
    cout<<count_paint << endl;
    return 0;
}
