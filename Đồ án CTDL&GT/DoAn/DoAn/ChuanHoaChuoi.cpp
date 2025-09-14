#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Xóa các khoảng trắng dư thừa
void removeSpace(char a[]) {
	int n = strlen(a);
	int start = 0;
	int end = n - 1;

	while (a[start] == ' ')
		start++;
	while (a[end] == ' ')
		end--;

	int j = 0;
	for (int i = start; i <= end; i++) {
		if (a[i] == ' ' && i < end && a[i + 1] == ' ')
			continue;
		else
			a[j++] = a[i];
	}
	a[j] = '\0';
}

// Hàm chuẩn hóa chuỗi
void chuanHoa(char a[]) {
	removeSpace(a);

	int n = strlen(a);
	if (a[0] >= 'a' && a[0] <= 'z')
		a[0] -= 32;
	for (int i = 1;i < n;i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] += 32;
		}
	}
}