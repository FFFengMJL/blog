#include <iostream>
using namespace std;

int find(int n, int m, int i, int line[]) {
    if (m == 2) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            if (j != i)
            max = max > line[j] ^ line[i] ? max : line[j] ^ line[i];
        }
        return max;
    }
    else {
        int max = 0;
        for (int j = 0; j < n; j++) {
            int midRes = line[i] ^ find(n, m - 1, j, line);
            max = max > midRes ? max : midRes;
        }
        return max;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int line[n];
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int mid = find(n, m, i, line);
        res = res > mid ? res : mid;
    }

    cout << res << endl;
}