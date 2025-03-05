#include <stdio.h>

// Hàm đệ quy tìm giá trị lớn nhất trong mảng
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];  // Nếu chỉ có một phần tử, trả về chính nó
    int maxRest = findMax(arr, n - 1);  // Tìm max trong n-1 phần tử đầu
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;  // So sánh phần tử cuối cùng với maxRest
}

// Hàm đệ quy tính tổng các phần tử của mảng
int sumArray(int arr[], int n) {
    if (n == 0) return 0;  // Nếu mảng rỗng, trả về 0
    return arr[n - 1] + sumArray(arr, n - 1);  // Tổng của phần tử cuối cùng + tổng của phần trước đó
}

// Hàm đệ quy đếm số phần tử chẵn
int countEven(int arr[], int n) {
    if (n == 0) return 0;  // Nếu mảng rỗng, không có số chẵn
    return ((arr[n - 1] % 2 == 0) ? 1 : 0) + countEven(arr, n - 1);
}

// Hàm hoán đổi hai giá trị
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm đệ quy đảo ngược mảng
void reverseArray(int arr[], int left, int right) {
    if (left >= right) return;  // Khi gặp nhau thì dừng
    swap(&arr[left], &arr[right]);  // Hoán đổi hai phần tử
    reverseArray(arr, left + 1, right - 1);  // Gọi đệ quy với phần còn lại
}

// Hàm đệ quy kiểm tra mảng đối xứng
bool isPalindrome(int arr[], int left, int right) {
    if (left >= right) return true;  // Khi gặp nhau hoặc giao nhau thì đúng
    if (arr[left] != arr[right]) return false;  // Nếu khác nhau thì không đối xứng
    return isPalindrome(arr, left + 1, right - 1);  // Kiểm tra phần còn lại
}

// Hàm đệ quy tìm vị trí phần tử x trong mảng
int findIndex(int arr[], int n, int x, int index) {
    if (index == n) return -1;  // Nếu duyệt hết mà không tìm thấy, trả về -1
    if (arr[index] == x) return index;  // Nếu tìm thấy, trả về vị trí
    return findIndex(arr, n, x, index + 1);  // Kiểm tra tiếp phần còn lại
}

int main() {
    int arr[] = {1, 5, 3, 9, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Gia tri lon nhat: %d\n", findMax(arr, n));
}

