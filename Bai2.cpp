#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;            // M� th� sinh (t? d?ng tang)
    char ten[101];     // T�n th� sinh
    char ngaySinh[11]; // Ng�y sinh
    float diem1, diem2, diem3; // �i?m 3 m�n thi
    float tongDiem;    // T?ng di?m
} ThiSinh;

// H�m nh?p th�ng tin th� sinh
void nhapThiSinh(ThiSinh *ts, int ma) {
    ts->ma = ma; // G�n m� th� sinh
    getchar();   // �?c b? k� t? xu?ng d�ng th?a
    fgets(ts->ten, 101, stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0'; // X�a k� t? '\n'
    fgets(ts->ngaySinh, 11, stdin);
    ts->ngaySinh[strcspn(ts->ngaySinh, "\n")] = '\0'; // X�a k� t? '\n'
    scanf("%f %f %f", &ts->diem1, &ts->diem2, &ts->diem3);
    ts->tongDiem = ts->diem1 + ts->diem2 + ts->diem3;
}

// H�m in th�ng tin th� sinh
void inThiSinh(ThiSinh ts) {
    printf("%d %s %s %.1f\n", ts.ma, ts.ten, ts.ngaySinh, ts.tongDiem);
}

// H�m s?p x?p danh s�ch th� sinh theo m� tang d?n
void sapXepTheoMa(ThiSinh ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].ma > ds[j].ma) {
                ThiSinh temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// H�m t�m th? khoa v� in ra danh s�ch th? khoa
void timThuKhoa(ThiSinh ds[], int n) {
    float diemCaoNhat = ds[0].tongDiem;
    for (int i = 1; i < n; i++) {
        if (ds[i].tongDiem > diemCaoNhat) {
            diemCaoNhat = ds[i].tongDiem;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem == diemCaoNhat) {
            inThiSinh(ds[i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Nh?p s? lu?ng th� sinh
    ThiSinh ds[n];

    // Nh?p th�ng tin cho t?ng th� sinh
    for (int i = 0; i < n; i++) {
        nhapThiSinh(&ds[i], i + 1); // M� th� sinh t? d?ng tang t? 1
    }

    // S?p x?p danh s�ch theo m� tang d?n
    sapXepTheoMa(ds, n);

    // T�m v� in danh s�ch th? khoa
    timThuKhoa(ds, n);

    return 0;
}
