#include <stdio.h>

int main() {
    int n = 0, i, j;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    int line1[n], res = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &line1[i]);
        if (line1[i] != 0) res += (line1[i] + 2);
        if (i == 0) res += line1[i];
        else { 
            res += (line1[i] > line1[i - 1] ? line1[i] - line1[i - 1] : line1[i - 1] - line1[i]);
            if (i == n - 1) res += line1[i]; 
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            int k = 0;
            scanf("%d", &k);
            if (k != 0) res += 2;
            res += line1[j] > k ? line1[j] - k : k - line1[j];
            if (j == 0) res += k;
            else {
                res += (k > line1[j - 1] ? k - line1[j - 1] : line1[j - 1] - k);
                if (j == n - 1) res += k;
            }
            line1[j] = k;
        }
    }

    for (i = 0; i < n; i++) {
        res += line1[i];
    }

    printf("%d\n", res);
    return 0;
}