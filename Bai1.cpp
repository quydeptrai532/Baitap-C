#include <stdio.h>
#include <ctype.h>
#include <string.h>

// H�m x�a kho?ng tr?ng th?a ? d?u v� cu?i chu?i
void xoaKhoangTrangThua(char *str) {
    int len = strlen(str);
    int i = 0;

    // X�a kho?ng tr?ng d?u chu?i
    while (i < len && isspace(str[i])) {
        i++;
    }

    if (i > 0) {
        memmove(str, str + i, len - i + 1);
    }

    len = strlen(str);

    // X�a kho?ng tr?ng cu?i chu?i
    i = len - 1;
    while (i >= 0 && isspace(str[i])) {
        str[i] = '\0';
        i--;
    }
}

// H�m chu?n h�a h? t�n
void chuanHoaHoTen(char *str) {
    xoaKhoangTrangThua(str); // X�a kho?ng tr?ng th?a
    int len = strlen(str);

    // Chuy?n d?i c�c t? trong chu?i
    int capitalize = 1; // C? d? bi?t khi n�o c?n vi?t hoa
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            capitalize = 1; // G?p kho?ng tr?ng th� t? sau s? vi?t hoa
        } else if (capitalize) {
            str[i] = toupper(str[i]); // Vi?t hoa ch? c�i d?u t?
            capitalize = 0;
        } else {
            str[i] = tolower(str[i]); // Vi?t thu?ng c�c ch? c�n l?i
        }
    }

    // X�a kho?ng tr?ng th?a gi?a c�c t?
    int index = 0; // V? tr� ghi l?i trong chu?i
    for (int i = 0; i < len; i++) {
        if (!(isspace(str[i]) && isspace(str[i + 1]))) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0'; // K?t th�c chu?i
}

int main() {
    char hoTen[101];
    printf("Nhap ho ten: ");
    fgets(hoTen, 101, stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // X�a k� t? xu?ng d�ng

    chuanHoaHoTen(hoTen);
    printf("Ho ten chuan: %s\n", hoTen);

    return 0;
}
