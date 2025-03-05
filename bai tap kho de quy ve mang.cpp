#include <stdio.h>
#include <stdbool.h>

// Ham hoan doi hai so nguyen
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham phan chia de sap xep theo QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi lam pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { // Neu phan tu nho hon pivot thi dua ve ben trai
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Dua pivot ve dung vi tri
    return (i + 1); // Tra ve chi so pivot moi
}

// Ham sap xep QuickSort de quy
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sap xep de quy hai nua cua mang
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Ham in mang
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Tim kiem nhi phan bang de quy
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) return mid; // Tim thay phan tu
        if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x); // Tim ben trai
        return binarySearch(arr, mid + 1, right, x); // Tim ben phai
    }
    return -1; // Khong tim thay
}

// Kiem tra so nguyen to bang de quy
bool isPrime(int n, int i) {
    if (n < 2) return false;
    if (i * i > n) return true; // Neu khong co uoc nao < sqrt(n), la SNT
    if (n % i == 0) return false; // Co uoc thi khong la SNT
    return isPrime(n, i + 1); // Kiem tra voi so tiep theo
}

// Tinh tong cac so nguyen to trong mang bang de quy
int sumPrimes(int arr[], int n) {
    if (n == 0) return 0;
    int sum = sumPrimes(arr, n - 1);
    if (isPrime(arr[n - 1], 2)) sum += arr[n - 1]; // Neu la SNT thi cong vao tong
    return sum;
}

// Tim tong lon nhat cua day con cat qua giua
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0, left_sum = -2147483648, right_sum = -2147483648;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }

    return left_sum + right_sum; // Tra ve tong lon nhat co chua mid
}

// Tim tong lon nhat cua day con lien tiep bang de quy
int maxSubArraySum(int arr[], int left, int right) {
    if (left == right) return arr[left]; // Chi co 1 phan tu

    int mid = (left + right) / 2;
    int left_max = maxSubArraySum(arr, left, mid);
    int right_max = maxSubArraySum(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    return (left_max > right_max) ? ((left_max > cross_max) ? left_max : cross_max) : ((right_max > cross_max) ? right_max : cross_max);
}

// Tim so xuat hien le lan bang XOR
int findOddOccurrence(int arr[], int n) {
    if (n == 1) return arr[0];
    return arr[n - 1] ^ findOddOccurrence(arr, n - 1); // Dung XOR de tim so le lan
}

// Phan chia cho QuickSelect
int partitionForSelect(int arr[], int left, int right) {
    int pivot = arr[right], i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

// Tim phan tu lon thu k bang QuickSelect
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];
    int pivotIndex = partitionForSelect(arr, left, right);
    if (k == pivotIndex) return arr[k];
    else if (k < pivotIndex) return quickSelect(arr, left, pivotIndex - 1, k);
    else return quickSelect(arr, pivotIndex + 1, right, k);
}

// Ham chinh
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    int x = 5;
    int index = binarySearch(arr, 0, n - 1, x);
    printf("Phan tu %d %s
", x, (index != -1) ? "tim thay" : "khong ton tai");

    printf("Tong cac so nguyen to: %d\n", sumPrimes(arr, n));
    printf("Tong lon nhat day con lien tiep: %d\n", maxSubArraySum(arr, 0, n - 1));

    int arr2[] = {2, 3, 5, 4, 5, 3, 4, 2, 4};
    printf("So xuat hien le lan: %d\n", findOddOccurrence(arr2, sizeof(arr2)/sizeof(arr2[0])));

    int k = 3;
    printf("Phan tu lon thu %d: %d\n", k, quickSelect(arr, 0, n - 1, k - 1));

    return 0;
}
