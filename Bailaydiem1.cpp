#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Hàm xóa kho?ng tr?ng th?a ? d?u và cu?i chu?i
void xoaKhoangTrangThua(char *str) {
    int len = strlen(str);
    int i = 0;

    // Xóa kho?ng tr?ng d?u chu?i
    while (i < len && isspace(str[i])) {
        i++;
    }

    if (i > 0) {
        memmove(str, str + i, len - i + 1);
    }

    len = strlen(str);

    // Xóa kho?ng tr?ng cu?i chu?i
    i = len - 1;
    while (i >= 0 && isspace(str[i])) {
        str[i] = '\0';
        i--;
    }
}

// Hàm chu?n hóa h? tên
void chuanHoaHoTen(char *str) {
    xoaKhoangTrangThua(str); // Xóa kho?ng tr?ng th?a
    int len = strlen(str);

    // Chuy?n d?i các t? trong chu?i
    int capitalize = 1; // C? d? bi?t khi nào c?n vi?t hoa
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            capitalize = 1; // G?p kho?ng tr?ng thì t? sau s? vi?t hoa
        } else if (capitalize) {
            str[i] = toupper(str[i]); // Vi?t hoa ch? cái d?u t?
            capitalize = 0;
        } else {
            str[i] = tolower(str[i]); // Vi?t thu?ng các ch? còn l?i
        }
    }

    // Xóa kho?ng tr?ng th?a gi?a các t?
    int index = 0; // V? trí ghi l?i trong chu?i
    for (int i = 0; i < len; i++) {
        if (!(isspace(str[i]) && isspace(str[i + 1]))) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0'; // K?t thúc chu?i
}

int main() {
    char hoTen[101];
    printf("Nhap ho ten: ");
    fgets(hoTen, 101, stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký t? xu?ng dòng

    chuanHoaHoTen(hoTen);
    printf("Ho ten chuan: %s\n", hoTen);

    return 0;
}
