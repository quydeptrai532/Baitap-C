#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Hàm ki?m tra s? có ph?i là dãy không gi?m hay không
int isNonDecreasing(int number) {
    int prevDigit = 10; // Giá tr? b?t d?u cho phép là 10 (ch? s? tru?c t?t c? các ch? s?)
    
    while (number > 0) {
        int digit = number % 10;
        if (digit > prevDigit) {
            return 0; // N?u có ch? s? nh? hon ch? s? tru?c dó, tr? v? 0
        }
        prevDigit = digit;
        number /= 10;
    }
    
    return 1; // N?u t?t c? ch? s? d?u không gi?m, tr? v? 1
}

int main() {
    char line[MAX_SIZE];
    int numbers[MAX_SIZE], count = 0;
    
    // Ð?c t?t c? các s? t? d?u vào
    printf("Nh?p dãy s? (k?t thúc b?ng EOF):\n");
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int num = 0;
            // Chuy?n d?i chu?i token thành s? nguyên
            for (int i = 0; token[i] != '\0'; i++) {
                if (isdigit(token[i])) {
                    num = num * 10 + (token[i] - '0');
                }
            }
            numbers[count++] = num;
            token = strtok(NULL, " \n");
        }
    }
    
    // M?ng d? d?m s? l?n xu?t hi?n c?a các s? không gi?m
    int freq[MAX_SIZE] = {0};
    
    // Duy?t qua t?ng s? trong m?ng numbers
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i])) {
            freq[numbers[i]]++;
        }
    }
    
    // In ra các s? không gi?m và s? l?n xu?t hi?n
    printf("Các s? không gi?m và s? l?n xu?t hi?n:\n");
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i]) && freq[numbers[i]] > 0) {
            printf("S? %d xu?t hi?n %d l?n\n", numbers[i], freq[numbers[i]]);
            freq[numbers[i]] = 0; // Ð?m b?o ch? in m?t l?n
        }
    }

    return 0;
}
