#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Ham hoan doi hai so nguyen
to// Dung de trao doi gia tri cua hai bien nguyen
to// Su dung trong hoan vi va dao nguoc chuoi
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham de quy dao nguoc chuoi
void reverseString(char str[], int left, int right) {
    if (left >= right) return; // Dieu kien dung
    swap((int*)&str[left], (int*)&str[right]); // Hoan doi hai ky tu
    reverseString(str, left + 1, right - 1); // Goi de quy cho phan con lai
}

// Ham de quy dem so ky tu trong chuoi
int countCharacters(char str[]) {
    if (str[0] == '\0') return 0; // Neu chuoi rong, tra ve 0
    return 1 + countCharacters(str + 1); // Tang bien dem va goi de quy
}

// Ham de quy tinh tong cac chu so trong chuoi
int sumDigits(char str[]) {
    if (str[0] == '\0') return 0; // Dieu kien dung
    int num = (str[0] >= '0' && str[0] <= '9') ? str[0] - '0' : 0; // Neu la so, lay gia tri so
    return num + sumDigits(str + 1); // Cong vao tong va goi de quy
}

// Ham de quy kiem tra Palindrome
bool isPalindrome(char str[], int left, int right) {
    if (left >= right) return true; // Dieu kien dung
    if (str[left] != str[right]) return false; // Neu ky tu khac nhau, khong phai palindrome
    return isPalindrome(str, left + 1, right - 1); // Goi de quy cho phan giua
}

// Ham de quy dem so lan xuat hien cua ky tu trong chuoi
int countCharOccurrences(char str[], char c) {
    if (str[0] == '\0') return 0; // Dieu kien dung
    return (str[0] == c) + countCharOccurrences(str + 1, c); // Dem va goi de quy
}

// Ham de quy loai bo ky tu trung lap trong chuoi
void removeDuplicates(char str[], int index, bool seen[256]) {
    if (str[index] == '\0') return; // Dieu kien dung
    if (seen[(unsigned char)str[index]]) { // Neu ky tu da xuat hien truoc do
        for (int i = index; str[i] != '\0'; i++)
            str[i] = str[i + 1]; // Dich trai ky tu
        removeDuplicates(str, index, seen); // Goi de quy lai tu vi tri hien tai
    } else {
        seen[(unsigned char)str[index]] = true;
        removeDuplicates(str, index + 1, seen); // Tiep tuc kiem tra ky tu tiep theo
    }
}

// Ham de quy sinh hoan vi cua chuoi
void permute(char str[], int l, int r) {
    if (l == r) { // Dieu kien dung: Khi da hoan vi xong
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap((int*)&str[l], (int*)&str[i]); // Hoan doi ky tu
        permute(str, l + 1, r); // Goi de quy cho phan con lai
        swap((int*)&str[l], (int*)&str[i]); // Hoan doi lai de tro ve trang thai ban dau
    }
}

// Ham de quy tao tat ca day con cua chuoi
void generateSubsequences(char str[], char temp[], int i, int j) {
    if (str[i] == '\0') { // Dieu kien dung
        temp[j] = '\0';
        if (j > 0) printf("%s\n", temp); // In ra day con
        return;
    }
    temp[j] = str[i]; // Chon ky tu hien tai
    generateSubsequences(str, temp, i + 1, j + 1); // Goi de quy voi ky tu hien tai
    generateSubsequences(str, temp, i + 1, j); // Bo qua ky tu hien tai va goi de quy
}

// Ham de quy tim do dai day con chung dai nhat giua hai chuoi
int longestCommonSubsequence(char str1[], char str2[], int m, int n) {
    if (m == 0 || n == 0) return 0; // Dieu kien dung
    if (str1[m - 1] == str2[n - 1]) // Neu ky tu cuoi giong nhau
        return 1 + longestCommonSubsequence(str1, str2, m - 1, n - 1);
    return (longestCommonSubsequence(str1, str2, m, n - 1) > longestCommonSubsequence(str1, str2, m - 1, n))
               ? longestCommonSubsequence(str1, str2, m, n - 1)
               : longestCommonSubsequence(str1, str2, m - 1, n);
}

// Ham chinh
int main() {
    char str1[] = "hello";
    reverseString(str1, 0, strlen(str1) - 1);
    printf("Chuoi dao nguoc: %s\n", str1);

    char str2[] = "hello123";
    printf("So ky tu trong chuoi: %d\n", countCharacters(str2));
    printf("Tong cac chu so trong chuoi: %d\n", sumDigits(str2));

    char str3[] = "madam";
    printf("Chuoi %s la palindrome? %s\n", str3, isPalindrome(str3, 0, strlen(str3) - 1) ? "Yes" : "No");

    char str4[] = "hello world";
    printf("So lan ky tu 'l' xuat hien: %d\n", countCharOccurrences(str4, 'l'));

    char str5[] = "aabbcc";
    bool seen[256] = {false};
    removeDuplicates(str5, 0, seen);
    printf("Chuoi sau khi loai bo ky tu trung lap: %s\n", str5);

    char str6[] = "abc";
    printf("Hoan vi cua chuoi:\n");
    permute(str6, 0, strlen(str6) - 1);

    char temp[100];
    printf("Cac day con cua chuoi:\n");
    generateSubsequences(str6, temp, 0, 0);

    char str7[] = "abcde", str8[] = "ace";
    printf("Do dai day con chung dai nhat: %d\n", longestCommonSubsequence(str7, str8, strlen(str7), strlen(str8)));

    return 0;
}