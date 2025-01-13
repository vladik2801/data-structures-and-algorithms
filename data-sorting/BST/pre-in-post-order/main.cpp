#include <iostream>
using namespace std;

string IsMaybe(int* pre, int* in, int* post, int count) {
    if (count == 0) {
        return "YES";
    }

    if (pre[0] != post[count - 1]) {
        return "NO";
    }

    int root = -1;
    for (int i = 0; i < count; i++) {
        if (in[i] == pre[0]) {
            root = i;
            break;
        }
    }
    if (root == -1) return "NO";

    int ltsize = root;
    int rtsize = count - root - 1;

    string left = IsMaybe(pre + 1, in, post, ltsize);
    string right = IsMaybe(pre + 1 + ltsize, in + root + 1, post + ltsize, rtsize);

    if (left == "YES" && right == "YES") {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int count_ver;
    cin >> count_ver;

    int* pre = new int[count_ver];
    int* in = new int[count_ver];
    int* post = new int[count_ver];

    for (int i = 0; i < count_ver; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < count_ver; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < count_ver; i++) {
        cin >> post[i];
    }

    cout << IsMaybe(pre, in, post, count_ver) << "\n";

    delete[] pre;
    delete[] in;
    delete[] post;

    return 0;
}
