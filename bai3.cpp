#include <stdio.h>

void nhapMaTran(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void tinhTich(int a[][100], int n, int m, int c[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * a[j][k];
            }
        }
    }
}

void inMaTran(int c[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t); // S? b? test
    for (int test = 1; test <= t; test++) {
        int n, m;
        scanf("%d%d", &n, &m);

        int a[100][100], c[100][100];
        nhapMaTran(a, n, m); // Nh?p ma tr?n A
        tinhTich(a, n, m, c); // Tính tích c?a A v?i A chuy?n v?

        printf("Test %d:\n", test);
        inMaTran(c, n); // In ma tr?n k?t qu?
    }
    return 0;
}
