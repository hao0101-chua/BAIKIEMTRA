#include <stdio.h>
#include <stdbool.h>

long long arr[10005];  // Mảng lưu trữ các số Fibonacci là số nguyên tố trong khoảng [a, b]
long long fi[100] = {0};  // Mảng nhớ (memoization) để lưu kết quả Fibonacci đã tính

// Hàm tính số Fibonacci bằng đệ quy có nhớ (Memoization)
long long fibonacy(int n) {
    if (n == 0 || n == 1) return n;  // Trường hợp cơ bản: F(0) = 0, F(1) = 1
    if (fi[n] != 0) return fi[n];  // Nếu đã tính trước đó, trả về kết quả đã lưu
    return fi[n] = fibonacy(n - 1) + fibonacy(n - 2);  // Lưu kết quả vào mảng fi và trả về
}

// Hàm kiểm tra một số có phải số nguyên tố hay không bằng đệ quy
bool primes(int n, int i = 2) {
    if (n < 2) return false;  // Số nhỏ hơn 2 không phải số nguyên tố
    if (n == 2) return true;  // Số 2 là số nguyên tố
    if (n % i == 0) return false;  // Nếu chia hết cho i, không phải số nguyên tố
    if (i * i > n) return true;  // Nếu i vượt căn bậc hai của n, thì n là số nguyên tố
    return primes(n, i + 1);  // Kiểm tra tiếp với i + 1
}

// Hàm tìm các số Fibonacci là số nguyên tố trong khoảng [a, b] bằng đệ quy
int Array(int a, int b, int i, long long arr[], int index) {
    long long fib = fibonacy(i);  // Tính số Fibonacci thứ i
    if (fib > b) return index;  // Nếu vượt quá b, dừng đệ quy và trả về số lượng phần tử
    if (fib >= a && primes(fib)) arr[index++] = fib;  // Nếu nằm trong khoảng và là số nguyên tố, thêm vào mảng
    return Array(a, b, i + 1, arr, index);  // Gọi đệ quy với i + 1
}

// Hàm tính tổng các chữ số của một số bằng đệ quy
long long Sum(long long n) {
    if (n < 10) return n;  // Nếu chỉ còn một chữ số, trả về chính nó
    return (n % 10) + Sum(n / 10);  // Lấy chữ số cuối cùng cộng với tổng chữ số còn lại
}

// Hàm tìm vị trí của phần tử có tổng chữ số nhỏ nhất (bị sai logic, cần sửa để tìm tổng lớn nhất)
int find_max_index(long long arr[], int n, int index, int max_index) {
    if (index == n) return max_index;  // Khi duyệt hết mảng, trả về chỉ mục của phần tử lớn nhất
    return find_max_index(arr, n, index + 1, Sum(arr[index]) > Sum(arr[max_index]) ? index : max_index);  
    // Nếu tổng chữ số của arr[index] lớn hơn tổng của arr[max_index], cập nhật max_index
}

// Hàm sắp xếp theo tổng chữ số giảm dần bằng Selection Sort đệ quy
void sort_desc(long long arr[], int n, int index) {
    if (index == n) return;  // Nếu đã sắp xếp hết, dừng đệ quy
    
    int max_index = find_max_index(arr, n, index, index);  // Tìm phần tử có tổng chữ số lớn nhất từ index trở đi
    
    // Hoán vị phần tử lớn nhất với phần tử đầu của đoạn chưa sắp xếp
    if (max_index != index) {
        long long temp = arr[max_index];
        arr[max_index] = arr[index];
        arr[index] = temp;
    }
    
    sort_desc(arr, n, index + 1);  // Gọi đệ quy để sắp xếp phần còn lại
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);  // Nhập khoảng [a, b]

    int count = Array(a, b, 0, arr, 0);  // Gọi hàm tìm số Fibonacci nguyên tố, lưu vào mảng và lấy số phần tử

    for (int i = 0; i < count; i++) printf("%lld ", arr[i]);  // In ra các số tìm được
    printf("\n");

    sort_desc(arr, count, 0);  // Sắp xếp theo tổng chữ số giảm dần

    for (int i = 0; i < count; i++) printf("%lld ", arr[i]);  // In mảng sau khi sắp xếp
}
