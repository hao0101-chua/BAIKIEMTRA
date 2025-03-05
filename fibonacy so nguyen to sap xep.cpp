#include <stdio.h>
#include <stdbool.h>

long long array[10005];

long long fibonacy(int n){
    if(n == 0 || n == 1) return n;
    return fibonacy(n - 1) + fibonacy(n - 2);
}

bool primes(int n, int i = 2){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % i == 0) return false;
    if(i * i > n) return true;
    return primes(n, i + 1);
}

int Array(int a, int b, int i, long long array[], int index){
    int fib = fibonacy(i);
    if(fib > b) return index;
    if(fib >= a && primes(fib)) array[index++] = fib;
    return Array(a, b, i + 1, array, index);
}

// Hàm sắp xếp Quick Sort đệ quy (giảm dần)
void Quicksort(long long array[], int left, int right){
    if(left >= right) return; // Điều kiện dừng
    long long pivot = array[(left + right) / 2]; // Chọn phần tử giữa làm pivot
    int i = left, j = right;
    while(i <= j){
        while(array[i] > pivot) i++; // Tìm phần tử nhỏ hơn pivot bên trái
        while(array[j] < pivot) j--; // Tìm phần tử lớn hơn pivot bên phải
        // Hoán đổi nếu cần
        if(i <= j){
            long long temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++; j--;
        }
    }
    Quicksort(array, left, j); // Đệ quy cho phần bên trái
    Quicksort(array, i, right); // Đệ quy cho phần bên phải
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int count = Array(a, b, 0, array, 0);
    for(int i = 0; i < count; i++) printf("%lld ", array[i]);
    printf("\n");
    Quicksort(array, 0, count - 1);
    for(int i = 0; i < count; i++) printf("%lld ", array[i]);
    return 0;
}