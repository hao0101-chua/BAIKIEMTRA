#include <stdio.h>   // Thư viện chuẩn cho nhập/xuất
#include <stdbool.h> // Thư viện cho kiểu bool (true/false)
#include <string.h>  // Thư viện xử lý chuỗi

// Hàm tính độ dài chuỗi
int stringLength(char str[]) {
    return strlen(str); // Sử dụng hàm strlen để tính độ dài chuỗi
}

// Hàm đảo ngược chuỗi
void reverseString(char str[]) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

// Hàm kiểm tra chuỗi Palindrome
bool isPalindrome(char str[]) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) return false; // Nếu hai ký tự không khớp, không phải palindrome
        left++;
        right--;
    }
    return true;
}

// Hàm đếm số lần xuất hiện của ký tự trong chuỗi
int countCharOccurrences(char str[], char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) count++; // Nếu ký tự khớp, tăng biến đếm
    }
    return count;
}

// Hàm loại bỏ ký tự trùng lặp trong chuỗi
void removeDuplicates(char str[]) {
    bool seen[256] = {false};
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = true;
            str[index++] = str[i];
        }
    }
    str[index] = '\0'; // Kết thúc chuỗi mới
}

// Hàm tìm độ dài dãy con chung dài nhất giữa hai chuỗi
int longestCommonSubsequence(char str1[], char str2[]) {
    int m = strlen(str1), n = strlen(str2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n];
}

// Hàm chính
int main() {
    char str1[] = "hello";
    printf("Do dai chuoi: %d\n", stringLength(str1));
    reverseString(str1);
    printf("Chuoi dao nguoc: %s\n", str1);

    char str2[] = "madam";
    printf("Chuoi %s la palindrome? %s\n", str2, isPalindrome(str2) ? "Yes" : "No");

    char str3[] = "hello world";
    printf("So lan ky tu 'l' xuat hien: %d\n", countCharOccurrences(str3, 'l'));

    char str4[] = "aabbcc";
    removeDuplicates(str4);
    printf("Chuoi sau khi loai bo ky tu trung lap: %s\n", str4);

    char str6[] = "abcde", str7[] = "ace";
    printf("Do dai day con chung dai nhat: %d\n", longestCommonSubsequence(str6, str7));

    return 0;
}
