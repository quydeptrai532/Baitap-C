#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;            // Mã thí sinh (t? d?ng tang)
    char ten[101];     // Tên thí sinh
    char ngaySinh[11]; // Ngày sinh
    float diem1, diem2, diem3; // Ði?m 3 môn thi
    float tongDiem;    // T?ng di?m
} ThiSinh;

// Hàm nh?p thông tin thí sinh
void nhapThiSinh(ThiSinh *ts, int ma) {
    ts->ma = ma; // Gán mã thí sinh
    getchar();   // Ð?c b? ký t? xu?ng dòng th?a
    fgets(ts->ten, 101, stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0'; // Xóa ký t? '\n'
    fgets(ts->ngaySinh, 11, stdin);
    ts->ngaySinh[strcspn(ts->ngaySinh, "\n")] = '\0'; // Xóa ký t? '\n'
    scanf("%f %f %f", &ts->diem1, &ts->diem2, &ts->diem3);
    ts->tongDiem = ts->diem1 + ts->diem2 + ts->diem3;
}

// Hàm in thông tin thí sinh
void inThiSinh(ThiSinh ts) {
    printf("%d %s %s %.1f\n", ts.ma, ts.ten, ts.ngaySinh, ts.tongDiem);
}

// Hàm s?p x?p danh sách thí sinh theo mã tang d?n
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

// Hàm tìm th? khoa và in ra danh sách th? khoa
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
    scanf("%d", &n); // Nh?p s? lu?ng thí sinh
    ThiSinh ds[n];

    // Nh?p thông tin cho t?ng thí sinh
    for (int i = 0; i < n; i++) {
        nhapThiSinh(&ds[i], i + 1); // Mã thí sinh t? d?ng tang t? 1
    }

    // S?p x?p danh sách theo mã tang d?n
    sapXepTheoMa(ds, n);

    // Tìm và in danh sách th? khoa
    timThuKhoa(ds, n);

    return 0;
}
