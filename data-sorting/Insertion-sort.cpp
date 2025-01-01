#include <iostream>

int main() {
    int count_slippers;
    std::cin>>count_slippers;
    int* massive_slippers = new int[count_slippers];
    for(int i=0;i<count_slippers;i++) {
        std::cin>>massive_slippers[i];
    }
    int sort_index = 0;
    int time_char;
    for (int i = 1; i < count_slippers; i++) {
        time_char = massive_slippers[i];
        int j = i - 1;
        for (j; j >= 0 && massive_slippers[j] > time_char ; j--) {
            massive_slippers[j+1] = massive_slippers[j];
        }
        massive_slippers[j+1] = time_char;
    }
    for (int i=0; i < count_slippers; ++i) {
        std::cout<<massive_slippers[i]<< " ";
    }
    delete[] massive_slippers;
    return 0;
}
