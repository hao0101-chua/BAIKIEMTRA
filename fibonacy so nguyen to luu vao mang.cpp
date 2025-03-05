#include <stdio.h>
#include <stdbool.h>

long long arr[10005];
long long fi[100] = {0};

long long fibonacy(int n){
    if(n == 0 || n == 1) return n;
    if(fi[n] != 0) return fi[n];
    return fi[n] = fibonacy(n - 1) + fibonacy(n - 2);
}

bool primes(int n, int i = 2){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % i == 0) return false;
    if(i * i > n) return true;
    return primes(n, i + 1);
}

int Array(int a, int b, int i, long long arr[], int index){
    int fib = fibonacy(i);
    if(fib > b) return index;
    if(fib >= a && primes(fib)) arr[index++] = fib;
    return Array(a, b, i + 1, arr, index);
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    int tmp = Array(a, b, 0, arr, 0);
    for(int i = 0; i < tmp; i++) printf("%lld ", arr[i]);
    return 0;
}
