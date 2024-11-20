#include <stdio.h>

// Hàm in dãy s?
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm th?c hi?n thu?t toán s?p x?p d?i ch? tr?c ti?p
void bubbleSort(int arr[], int n) {
    printf("Dãy ban d?u: ");
    printArray(arr, n);
    
    for (int i = 0; i < n - 1; i++) { // L?p qua các vòng
        printf("Bu?c %d:\n", i + 1);
        int swapped = 0; // Ð? ki?m tra có d?i ch? hay không
        
        for (int j = 0; j < n - i - 1; j++) { // So sánh t?ng c?p
            if (arr[j] > arr[j + 1]) { // Ð?i ch? n?u không dúng th? t?
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n); // In tr?ng thái sau m?i bu?c
        
        // N?u không có s? d?i ch? nào, dãy dã s?p x?p xong
        if (!swapped) {
            printf("Không có hoán v?, dãy dã s?p x?p.\n");
            break;
        }
    }
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Nh?p các ph?n t?:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Dãy dã s?p x?p: ");
    printArray(arr, n);
    
    return 0;
}
