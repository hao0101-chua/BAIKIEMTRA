#include <stdio.h>   // Thư viện chuẩn cho nhập/xuất
#include <stdbool.h> // Thư viện cho kiểu bool (true/false)
#include <string.h>  // Thư viện xử lý chuỗi

// Ham tinh do dai chuoi
int stringLength(char str[]) {
    return strlen(str); // Su dung ham strlen de tinh do dai chuoi
}

// Ham dao nguoc chuoi
void reverseString(char str[]) {
    int left = 0, right = strlen(str) - 1; // Xac dinh hai diem dau va cuoi cua chuoi
    while (left < right) {
        char temp = str[left]; // Hoan doi ky tu
        str[left] = str[right];
        str[right] = temp;
        left++;   // Tang chi so ben trai
        right--;  // Giam chi so ben phai
    }
}

// Ham kiem tra chuoi co phai Palindrome hay khong
bool isPalindrome(char str[]) {
    int left = 0, right = strlen(str) - 1; // Xac dinh hai diem dau va cuoi cua chuoi
    while (left < right) {
        if (str[left] != str[right]) return false; // Neu co ky tu khac nhau -> Khong phai Palindrome
        left++;
        right--;
    }
    return true; // Neu khong co su khac biet thi la Palindrome
}

// Ham dem so lan xuat hien cua ky tu trong chuoi
int countCharOccurrences(char str[], char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) { // Duyet tung ky tu trong chuoi den khi gap ky tu ket thuc '\0'
        if (str[i] == c) count++; // Neu ky tu trung khop, tang bien dem
    }
    return count;
}

// Ham loai bo ky tu trung lap trong chuoi
void removeDuplicates(char str[]) {
    bool seen[256] = {false}; // Mang danh dau ky tu da xuat hien hay chua
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!seen[(unsigned char)str[i]]) { // Neu ky tu chua xuat hien truoc do
            seen[(unsigned char)str[i]] = true; // Danh dau la da xuat hien
            str[index++] = str[i]; // Giu lai ky tu
        }
    }
    str[index] = '\0'; // Ket thuc chuoi sau khi loai bo ky tu trung lap
}

// Ham sinh hoan vi cua chuoi su dung de quy
void permute(char str[], int l, int r) {
    if (l == r) { // Neu da hoan thanh mot hoan vi
        printf("%s\n", str); // In hoan vi do
        return;
    }
    for (int i = l; i <= r; i++) {
        char temp = str[l]; // Hoan doi ky tu
        str[l] = str[i];
        str[i] = temp;
        permute(str, l + 1, r); // Goi de quy de hoan vi tiep cac ky tu con lai
        temp = str[l]; // Hoan doi lai de tra ve trang thai ban dau
        str[l] = str[i];
        str[i] = temp;
    }
}

// Ham tim do dai day con chung dai nhat (LCS) giua hai chuoi
int longestCommonSubsequence(char str1[], char str2[]) {
    int m = strlen(str1), n = strlen(str2);
    int dp[m+1][n+1]; // Mang dp luu tru ket qua trung gian
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // Neu mot chuoi rong thi LCS = 0
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1; // Neu ky tu giong nhau, tang do dai LCS
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]; // Lay gia tri lon hon giua hai truong hop
        }
    }
    return dp[m][n]; // Tra ve do dai LCS
}

// Ham chinh
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

    char str5[] = "abc";
    printf("Hoan vi cua chuoi:\n");
    permute(str5, 0, strlen(str5) - 1);

    char str6[] = "abcde", str7[] = "ace";
    printf("Do dai day con chung dai nhat: %d\n", longestCommonSubsequence(str6, str7));

    return 0;
}